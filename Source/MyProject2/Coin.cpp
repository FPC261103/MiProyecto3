#include "Coin.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstance.h"
#include "MyProject2BlockGrid.h" 

ACoin::ACoin()
{
    // 1. Componente raíz
    DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
    RootComponent = DummyRoot;

    // 2. Componente de malla, unido a la raíz
    CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh0"));
    CoinMesh->SetupAttachment(DummyRoot);

    // 3. Carga de la malla básica del cilindro
    ConstructorHelpers::FObjectFinderOptional<UStaticMesh> Cilindro(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
    CoinMesh->SetStaticMesh(Cilindro.Get());            // PISTA: método que asigna una malla estática (Set + Static + Mesh).

    // 4. Escala: el cilindro mide 100 x 100 x 100 unidades; se reduce su altura (eje Z)
    CoinMesh->SetRelativeScale3D(FVector(0.8f, 0.8f, 0.08f));   // PISTA: grosor de 8 unidades -> 8 / 100.

    // 5. Colisión para poder recibir clics del ratón
    CoinMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    CoinMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

    // 6. Materiales existentes en el proyecto
    ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> Orange(TEXT("/Game/Puzzle/Meshes/OrangeMaterial.OrangeMaterial"));
    ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> Blue(TEXT("/Game/Puzzle/Meshes/BlueMaterial.BlueMaterial"));
    MatCara = Orange.Get();
    MatSello = Blue.Get();

    // 7. Conexión del evento de clic
    CoinMesh->OnClicked.AddDynamic(this, &ACoin::CoinClicked);

    // Inicializar el puntero a la grilla 
    OwningGrid = nullptr;
}

void ACoin::BeginPlay()
{
    Super::BeginPlay();

    if (bLadoAleatorio)
    {
        bEsCara = FMath::RandBool();      // PISTA: función de FMath que devuelve true o false al azar (Rand + Bool).
    }

    MostrarLado();
}

void ACoin::MostrarLado()
{
    if (bEsCara)                          // PISTA: atributo que indica si el lado visible es CARA.
    {
        CoinMesh->SetMaterial(0, MatCara);
    }
    else
    {
        CoinMesh->SetMaterial(0, MatSello);
    }
}

void ACoin::CoinClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
    bEsCara = FMath::RandBool();                // Lanzamiento aleatorio
    Lanzamientos++;                             // PISTA: incrementar el atributo Lanzamientos
    MostrarLado();

    UE_LOG(LogTemp, Warning, TEXT("Moneda %s: %s - lanzamientos: %d"),
        *GetName(),
        bEsCara ? TEXT("CARA") : TEXT("SELLO"), // PISTA: macro que convierte el literal
        Lanzamientos);

    // Notificación a la grilla 
    if (bEsCara && OwningGrid)      // PISTA: puntero a la grilla; se comprueba que no sea nulo.
    {
        OwningGrid->AddScore(Puntos); 
    }
}