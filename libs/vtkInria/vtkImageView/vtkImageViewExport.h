#ifndef VTKIMAGEVIEWEXPORT_H
#define VTKIMAGEVIEWEXPORT_H

#ifdef WIN32
 #if defined (vtkWidgetsAddOn_EXPORTS)
  #define VTK_IMAGEVIEW_EXPORT __declspec( dllexport )
 #else
  #define VTK_IMAGEVIEW_EXPORT __declspec( dllimport )
 #endif
#else
    #define VTK_IMAGEVIEW_EXPORT
#endif

#endif // VTKIMAGEVIEWEXPORT_H
 

