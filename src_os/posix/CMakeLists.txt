set(SOURCE_FILES
	${SOURCE_FILES}

	#Cryptography
	${CMAKE_CURRENT_SOURCE_DIR}/Cryptography/SecureRandomNumberGenerator.cpp

	#EventHandling
	${CMAKE_CURRENT_SOURCE_DIR}/Eventhandling/EventQueue.cpp

	#Multitasking
	${CMAKE_CURRENT_SOURCE_DIR}/Multitasking/Thread.cpp

	#Streams
	${CMAKE_CURRENT_SOURCE_DIR}/Streams/FileInputStream.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Streams/FileOutputStream.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Streams/FileUpdateStream.cpp

	PARENT_SCOPE)