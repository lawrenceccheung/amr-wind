target_sources(${amr_wind_lib_name}
  PRIVATE

  BoussinesqBubble.cpp
  BoussinesqBubbleFieldInit.cpp
  ChannelFlow.cpp
  RayleighTaylor.cpp
  RayleighTaylorFieldInit.cpp
  TaylorGreenVortex.cpp
  FreeStream.cpp
  ConvectingTaylorVortex.cpp
  EkmanSpiral.cpp
  SyntheticTurbulence.cpp
  HybridRANSLESABL.cpp
  VortexRing.cpp
  ScalarAdvection.cpp
  VortexDipole.cpp
  BurggrafFlow.cpp
  ActuatorSourceTagging.cpp
  Intermittency.cpp
  )

add_subdirectory(multiphase)
add_subdirectory(udfs)

if(AMR_WIND_ENABLE_MASA)
  add_subdirectory(mms)
endif()
