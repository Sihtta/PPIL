add_executable(test_geometrie
    test_geometrie.cpp
    ../src/core/Vecteur2D.cpp
    ../src/core/Color.cpp
    ../src/formes/Forme.cpp
    ../src/formes/Segment.cpp
    ../src/formes/Cercle.cpp
    ../src/formes/Triangle.cpp
    ../src/formes/Polygone.cpp
    ../src/formes/Groupe.cpp
    ../src/transformations/Transformation.cpp
    ../src/transformations/Translation.cpp
    ../src/transformations/Rotation.cpp
    ../src/transformations/Homothetie.cpp
    ../src/visitors/VisiteurSauvegarde.cpp
)

target_include_directories(test_geometrie PRIVATE ../include)
