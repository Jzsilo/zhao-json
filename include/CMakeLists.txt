set(HEADERS
        noncopyable.hpp
        FileReadStream.hpp
        FileWriteStream.hpp
        StringReadStream.hpp
        StringWriteStream.hpp
        Value.hpp
        Exception.hpp
        Writer.hpp
        Reader.hpp
        Document.hpp
)

add_library(zhao-json STATIC ${HEADERS})
set_target_properties(zhao-json PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS zhao-json DESTINATION lib)

install(FILES ${HEADERS} DESTINATION include)