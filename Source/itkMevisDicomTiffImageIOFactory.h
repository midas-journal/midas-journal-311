/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkMevisDicomTiffImageIOFactory.h,v $
  Language:  C++
  Date:      $Date: 2009/10/14 13:28:12 $
  Version:   $Revision: 1.7 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkMevisDicomTiffImageIOFactory_h
#define __itkMevisDicomTiffImageIOFactory_h

#include "itkObjectFactoryBase.h"
#include "itkImageIOBase.h"

namespace itk
{
/** \class MevisDicomTiffImageIOFactory
 * \brief Create instances of MevisDicomTiffImageIO objects using an object factory.
 */
class ITK_EXPORT MevisDicomTiffImageIOFactory : public ObjectFactoryBase
{
public:  
  /** Standard class typedefs. */
  typedef MevisDicomTiffImageIOFactory       Self;
  typedef ObjectFactoryBase        Superclass;
  typedef SmartPointer<Self>       Pointer;
  typedef SmartPointer<const Self> ConstPointer;
  
  /** Class methods used to interface with the registered factories. */
  virtual const char* GetITKSourceVersion() const;
  virtual const char* GetDescription() const;
  
  /** Method for class instantiation. */
  itkFactorylessNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(MevisDicomTiffImageIOFactory, ObjectFactoryBase);

  /** Register one factory of this type  */
  static void RegisterOneFactory()
    {
    MevisDicomTiffImageIOFactory::Pointer metaFactory = MevisDicomTiffImageIOFactory::New();
    ObjectFactoryBase::RegisterFactory(metaFactory);
    }

protected:
  MevisDicomTiffImageIOFactory();
  ~MevisDicomTiffImageIOFactory();

private:
  MevisDicomTiffImageIOFactory(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

};
 
} // end namespace itk

#endif
