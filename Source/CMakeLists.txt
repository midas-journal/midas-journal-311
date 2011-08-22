INCLUDE(${CMAKE_SOURCE_DIR}/IJMacros.txt)

#Change PROJECT_NAME to the name of your project
PROJECT(MevisDicomTiff)

#The following lines are required to use Dart
ENABLE_TESTING()
INCLUDE(Dart)

#Declare any external dependencies that your project may have here.
#examples include: ITK, VTK, JPEG, PNG, OpenGL, ZLIB, Perl, Java
#If you're not sure what name to use, look in the Modules directory of your
#cmake install and check that a file named Find(Package).cmake exists
#
# The packages can be specified with a version number, for example:
#
# ITK 2.8.1
# ITK 3.2.0
#
# If no version is specified, the most recent release of the package
# will be used.
# dcm/tiff developed using gdcm 2.0.10
# and tiff 3.7.8
SET(Required_Packages
ITK
GDCM
TIFF
)

#this foreach loads all of the packages that you specified as required.
#It shouldn't need to be modified.
FOREACH(Package ${Required_Packages})
  LOADPACKAGE(${Package})
ENDFOREACH(Package)

#Set any libraries that your project depends on.
#examples: ITKCommon, VTKRendering, etc
SET(Libraries
ITKCommon
ITKIO
)

#the following block of code is an example of how to build an executable in
#cmake.  Unmodified, it will add an executable called "MyExe" to the project.
#MyExe will be built using the files MyClass.h and MyClass.cxx, and it will
#be linked to all the libraries you specified above. 
#You can build more than one executable per project
ADD_LIBRARY(MevisIO 
            itkMevisDicomTiffImageIO.cxx
            itkMevisDicomTiffImageIOFactory.cxx)

SET(CurrentExe "ImageCompare")
ADD_EXECUTABLE(${CurrentExe} ImageCompare.cxx) 
TARGET_LINK_LIBRARIES(${CurrentExe} ${Libraries})


SET(CurrentExe "ImageCompareMevisIO")
ADD_EXECUTABLE(${CurrentExe} ImageCompareMevisIO.cxx) 
TARGET_LINK_LIBRARIES(${CurrentExe} MevisIO ${Libraries})

SET(CurrentExe "itkMevisTest")
ADD_EXECUTABLE(${CurrentExe} itkMevisTest.cxx) 
TARGET_LINK_LIBRARIES(${CurrentExe} MevisIO ${Libraries})

#the following line is an example of how to add a test to your project.
#Testname is the title for this particular test.  ExecutableToRun is the
#program which will be running this test.  It can either be a part of this
#project or an external executable.  After that list any args that are needed
#for this test.  Include as many tests as you like.  If your project doesn't have
#any tests you can comment out or delete the following line.

# READING
ADD_TEST(RUINT16-real itkMevisTest 0
    ${CMAKE_SOURCE_DIR}/../Data/img00-uint16.dcm ${CMAKE_SOURCE_DIR}/../Data/img00-uint16-test.vtk)
ADD_TEST(RUINT8 itkMevisTest 1 
    ${CMAKE_SOURCE_DIR}/../Data/img01-uint8.dcm ${CMAKE_SOURCE_DIR}/../Data/img01-uint8-test.vtk)
ADD_TEST(RINT8 itkMevisTest 2 
    ${CMAKE_SOURCE_DIR}/../Data/img02-int8.dcm ${CMAKE_SOURCE_DIR}/../Data/img02-int8-test.vtk)
ADD_TEST(RUINT16 itkMevisTest 3 
    ${CMAKE_SOURCE_DIR}/../Data/img03-uint16.dcm ${CMAKE_SOURCE_DIR}/../Data/img03-uint16-test.vtk)
ADD_TEST(RINT16 itkMevisTest 4 
    ${CMAKE_SOURCE_DIR}/../Data/img04-int16.dcm ${CMAKE_SOURCE_DIR}/../Data/img04-int16-test.vtk)
ADD_TEST(RUINT32 itkMevisTest 5 
    ${CMAKE_SOURCE_DIR}/../Data/img05-uint32.dcm ${CMAKE_SOURCE_DIR}/../Data/img05-uint32-test.vtk)
ADD_TEST(RINT32 itkMevisTest 6 
    ${CMAKE_SOURCE_DIR}/../Data/img06-int32.dcm ${CMAKE_SOURCE_DIR}/../Data/img06-int32-test.vtk)
ADD_TEST(RFLOAT itkMevisTest 7 
    ${CMAKE_SOURCE_DIR}/../Data/img07-float.dcm ${CMAKE_SOURCE_DIR}/../Data/img07-float-test.vtk)

ADD_TEST(R-comp-uint16-real ImageCompare 
    ${CMAKE_SOURCE_DIR}/../Data/img00-uint16-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img00-uint16-base.vtk)
ADD_TEST(R-comp-uint8 ImageCompare
    ${CMAKE_SOURCE_DIR}/../Data/img01-uint8-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img01-uint8-base.vtk)
ADD_TEST(R-comp-int8 ImageCompare
    ${CMAKE_SOURCE_DIR}/../Data/img02-int8-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img02-int8-base.vtk)
ADD_TEST(R-comp-uint16 ImageCompare
    ${CMAKE_SOURCE_DIR}/../Data/img03-uint16-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img03-uint16-base.vtk)
ADD_TEST(R-comp-int16 ImageCompare
    ${CMAKE_SOURCE_DIR}/../Data/img04-int16-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img04-int16-base.vtk)
ADD_TEST(R-comp-uint32 ImageCompare
    ${CMAKE_SOURCE_DIR}/../Data/img05-uint32-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img05-uint32-base.vtk )
ADD_TEST(R-comp-int32 ImageCompare
    ${CMAKE_SOURCE_DIR}/../Data/img06-int32-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img06-int32-base.vtk )
ADD_TEST(R-comp-float ImageCompare
    ${CMAKE_SOURCE_DIR}/../Data/img07-float-test.vtk ${CMAKE_SOURCE_DIR}/../Data/img07-float-base.vtk )

# WRITING (only tiff comparisons)
ADD_TEST(WUINT16-real itkMevisTest 0 
    ${CMAKE_SOURCE_DIR}/../Data/img00-uint16.vtk ${CMAKE_SOURCE_DIR}/../Data//img00-uint16-test.tiff)
ADD_TEST(WUINT8 itkMevisTest 1 
    ${CMAKE_SOURCE_DIR}/../Data/img01-uint8.vtk ${CMAKE_SOURCE_DIR}/../Data/img01-uint8-test.tiff)
ADD_TEST(WINT8 itkMevisTest 2 
    ${CMAKE_SOURCE_DIR}/../Data/img02-int8.vtk ${CMAKE_SOURCE_DIR}/../Data//img02-int8-test.tiff)
ADD_TEST(WUINT16 itkMevisTest 3 
    ${CMAKE_SOURCE_DIR}/../Data/img03-uint16.vtk ${CMAKE_SOURCE_DIR}/../Data/img03-uint16-test.tiff)
ADD_TEST(WINT16 itkMevisTest 4 
    ${CMAKE_SOURCE_DIR}/../Data/img04-int16.vtk ${CMAKE_SOURCE_DIR}/../Data/img04-int16-test.tiff)
ADD_TEST(WUINT32 itkMevisTest 5 
    ${CMAKE_SOURCE_DIR}/../Data/img05-uint32.vtk ${CMAKE_SOURCE_DIR}/../Data/img05-uint32-test.tiff)
ADD_TEST(WINT32 itkMevisTest 6 
    ${CMAKE_SOURCE_DIR}/../Data/img06-int32.vtk ${CMAKE_SOURCE_DIR}/../Data/img06-int32-test.tiff)
ADD_TEST(WFLOAT itkMevisTest 7 
    ${CMAKE_SOURCE_DIR}/../Data/img07-float.vtk ${CMAKE_SOURCE_DIR}/../Data/img07-float-test.tiff)

ADD_TEST(W-comp-uint16-real ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img00-uint16-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img00-uint16-base.tiff)
ADD_TEST(W-comp-uint8 ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img01-uint8-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img01-uint8-base.tiff)
ADD_TEST(W-comp-int8 ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img02-int8-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img02-int8-base.tiff)
ADD_TEST(W-comp-uint16 ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img03-uint16-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img03-uint16-base.tiff)
ADD_TEST(W-comp-int16 ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img04-int16-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img04-int16-base.tiff)
ADD_TEST(W-comp-uint32 ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img05-uint32-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img05-uint32-base.tiff)
ADD_TEST(W-comp-int32 ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img06-int32-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img06-int32-base.tiff)
ADD_TEST(W-comp-float ImageCompareMevisIO 
    ${CMAKE_SOURCE_DIR}/../Data/img07-float-test.tiff ${CMAKE_SOURCE_DIR}/../Data/img07-float-base.tiff)





#Once you're done modifying this template, you should rename it to "CMakeLists.txt"
