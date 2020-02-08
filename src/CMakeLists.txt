add_library(abstractcpp
	AbstractCPP.cpp
	abstractcpp/date.cpp
	abstractcpp/string.cpp
	abstractcpp/arrays.cpp
)

target_include_directories(abstractcpp
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
)