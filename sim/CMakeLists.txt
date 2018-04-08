# Configure source
set (ASEBASIM_SRC
        EnkiGlue.cpp
        AsebaGlue.cpp
        DirectAsebaGlue.cpp
        Door.cpp
        robots/e-puck/EPuck.cpp
        robots/e-puck/EPuck-descriptions.c
        robots/thymio2/Thymio2.cpp
        robots/thymio2/Thymio2-natives.cpp
        robots/thymio2/Thymio2-descriptions.c
        )

add_library(asebasim ${ASEBASIM_SRC})
set_target_properties(asebasim PROPERTIES VERSION ${LIB_VERSION_STRING}
        SOVERSION ${LIB_VERSION_MAJOR})

install(TARGETS asebasim
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR})