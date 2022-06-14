if(LOCAL_REPOSITORIES_BASE_DIR)
  FetchContent_Declare(msgpackc SOURCE_DIR ${LOCAL_REPOSITORIES_BASE_DIR}/msgpack-c)
else()
  FetchContent_Declare(
    msgpackc
    GIT_REPOSITORY https://github.com/msgpack/msgpack-c.git
    GIT_TAG cpp-4.1.1
    GIT_SHALLOW ON)
endif()
