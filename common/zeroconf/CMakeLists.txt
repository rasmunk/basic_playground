find_package(Qt5Core REQUIRED)

qt5_wrap_cpp(asebacommon_zeroconf_MOCS
	zeroconf-qt.h
)
set(ASEBA_ZEROCONFQT_SRC
	${asebacommon_zeroconf_MOCS}
	zeroconf-qt.cpp
)
add_library(asebazeroconfqt ${ASEBA_ZEROCONFQT_SRC})
set_target_properties(asebazeroconfqt PROPERTIES VERSION ${LIB_VERSION_STRING})
target_include_directories(asebazeroconfqt PUBLIC ${DNSSD_INCLUDE_DIRS})
qt5_use_modules(asebazeroconfqt Network)

install(TARGETS asebazeroconfqt
	LIBRARY DESTINATION ${LIB_INSTALL_DIR}
	ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
)

set (ASEBAZEROCONFQT_HDR
	zeroconf-qt.h
)
install(FILES ${ASEBAZEROCONFQT_HDR}
	DESTINATION include/aseba/common/zeroconf
)