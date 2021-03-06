# AACE Alexa Engine

# Find AVS
find_package(AVS 1.7.1)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AlertsEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/NotificationsEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AlexaClientEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AlexaEngineService.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AlexaEngineLogger.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AlexaEngineClientObserver.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AudioChannelEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AudioPlayerEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/PlaybackControllerEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/SpeechRecognizerEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/SpeechSynthesizerEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/TemplateRuntimeEngineImpl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE/Engine/Alexa/AuthProviderEngineImpl.h
)

source_group("Header Files" FILES ${HEADERS})

add_library(AACEAlexaEngine SHARED
    ${HEADERS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AlertsEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/NotificationsEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AlexaClientEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AlexaEngineService.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AlexaConfigurationImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AlexaEngineLogger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AlexaEngineClientObserver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AudioChannelEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AudioPlayerEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PlaybackControllerEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SpeechRecognizerEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SpeechSynthesizerEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TemplateRuntimeEngineImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AuthProviderEngineImpl.cpp
)

target_include_directories(AACEAlexaEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${AVS_INCLUDE_DIRS}
)

target_link_libraries(AACEAlexaEngine
    PUBLIC
        AACEAlexaPlatform
        AACECoreEngine
    PRIVATE
        ${AVS_LIBRARIES}
)

if(AMAZONLITE_KEY_WORD_DETECTOR)
    add_definitions(-DAMAZONLITE_WAKEWORD_SUPPORT)
    find_path(AMAZONLITE_INCLUDE_DIR AmazonLite/PryonLiteKeywordDetector.h
        CMAKE_FIND_ROOT_PATH_BOTH
    )
    find_library(AMAZONLITE_LIBRARY AMAZONLITE
        CMAKE_FIND_ROOT_PATH_BOTH
    )
    find_library(AVS_KWD_PROVIDER_LIBRARY KeywordDetectorProvider
        CMAKE_FIND_ROOT_PATH_BOTH
    )
    target_include_directories(AACEAlexaEngine
        PRIVATE
            ${AMAZONLITE_INCLUDE_DIR}
    )
    target_link_libraries(AACEAlexaEngine
        PRIVATE
            ${AVS_KWD_PROVIDER_LIBRARY}
            ${AMAZONLITE_LIBRARY}
    )
endif()

install(
    TARGETS AACEAlexaEngine
    DESTINATION lib
    EXPORT AACEAlexa
)

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/AACE
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
