/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkMevisTest.cxx,v $
  Language:  C++
  Date:      $Date: 2009/01/14 15:42:58 $
  Version:   $Revision: 1.1 $

=========================================================================*/
#if defined (_MSC_VER)
#pragma warning (disable: 4786)
#endif

#ifdef __BORLANDC__
#define ITK_LEAN_AND_MEAN
#endif

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "itkObjectFactoryBase.h"
#include "itkMevisDicomTiffImageIOFactory.h"
#include "itkMevisDicomTiffImageIO.h"

#include <cstdlib>
#include <iostream>

int main (int argc, char ** argv)
{
    if (argc < 4)
    {
        std::cout << argv[0] << " nr infile outfile" << std::endl;
        std::cout << "missing arguments" << std::endl;
        return EXIT_FAILURE;
    }

    const unsigned int D = 3;
    const unsigned int n = std::atoi(argv[1]);

    // register to factory base
    typedef itk::MevisDicomTiffImageIOFactory IOF;
    IOF::Pointer iof = IOF::New();
    itk::ObjectFactoryBase::RegisterFactory(iof);

    // READING/WRITING
    // note that each writing of a dcm file creates an unique
    // pt id and serie id number, hence only tiff comparison
    bool t(false);
    if (n == 0 )
    {
        t = true;
        typedef itk::Image<unsigned short,D>        IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }
    if (n == 1 )
    {
        t = true;
        typedef itk::Image<unsigned char,D>         IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }
    if (n == 2 )
    {
        t = true;
        typedef itk::Image<char,D>                  IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }
    if (n == 3 )
    {
        t = true;
        typedef itk::Image<unsigned short,D>                  IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }
    if (n == 4 )
    {
        t = true;
        typedef itk::Image<short,D>                  IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }
    if (n == 5 )
    {
        t = true;
        typedef itk::Image<unsigned int,D>                  IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }
    if (n == 6 )
    {
        t = true;
        typedef itk::Image<int,D>                  IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }
    if (n == 7 )
    {
        t = true;
        typedef itk::Image<float,D>                  IT;
        typedef itk::ImageFileReader<IT>            RT;
        RT::Pointer r = RT::New();
        r->SetFileName(argv[2]);
        r->Update();

        typedef itk::ImageFileWriter<IT>            WT;
        WT::Pointer w = WT::New();
        w->SetFileName(argv[3]);
        w->SetInput(r->GetOutput());
        w->Update();
    }

    if (!t)
    {
        std::cout << "no test run" << std::endl;
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}

