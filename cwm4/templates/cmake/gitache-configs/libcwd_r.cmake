gitache_config(
	GIT_REPOSITORY
		"https://github.com/CarloWood/libcwd.git"
		"https://github.com/CarloWood/cwds.git"
	GIT_TAG
		"master"
	CMAKE_ARGS
	"-DEnableLibcwdAlloc:BOOL=ON -DEnableLibcwdLocation:BOOL=ON"
)
