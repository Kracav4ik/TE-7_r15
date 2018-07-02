set(EXE_NAME "TE-7_r15")

set(SOURCE_FILES
        main.cpp
        Block.cpp
        Block.h
        RenderManager.cpp
        RenderManager.h
        GameManager.cpp
        GameManager.h
        InputManager.cpp
        InputManager.h
        Singleton.h
        GameEvent.h
        GameObject.h
        Renderable.h
)

add_executable(${EXE_NAME} ${SOURCE_FILES})

target_link_libraries(${EXE_NAME} ${SDL2_LIBRARY})

add_custom_command(
        TARGET ${EXE_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${SDL2_PATH}/bin/SDL2.dll
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
