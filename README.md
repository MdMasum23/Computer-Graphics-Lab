# Computer Graphics Lab

This repository contains implementations of various **Computer Graphics Lab Tasks** using C++ and the **graphics.h** library.


## Graphics Programming Setup with TDM-GCC and Code::Blocks  

To set up your system for running C++ graphics programs:  

1. **Download TDM-GCC 32-Bit Compiler**:  
   - [TDM-GCC 32-Bit Compiler](https://jmeubank.github.io/tdm-gcc/)  
   - Install it to `C:\TDM-GCC-32`.  

2. **Download Graphics Library**:  
   - [Graphics Library](https://drive.google.com/file/d/1z19xxKm2YseQi7QGxqCCdJ-lLfiEGuCm/view)  
   - Extract the library and move:  
     - `graphics.h` and `winbgim.h` to `C:\TDM-GCC-32\include`.  
     - `libbgi.a` to `C:\TDM-GCC-32\lib`.  

3. **Configure Code::Blocks**:  
   - Open Code::Blocks → `Settings -> Compiler`.  
   - Set **Compiler's installation directory** to `C:\TDM-GCC-32`.  
   - Go to `Linker Settings -> Other Linker Options` and add:  
     ```  
     -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32  
     ```  

4. **Run a Graphics Program**:  
   - Open a `.cpp` file, build, and run it in Code::Blocks.  


### Moving Car and Sun Output:

![Moving Car and Sun](https://github.com/user-attachments/assets/af28bda3-0b62-43b6-977f-28b3010646d3)

### natural scenery Output:

![natural scenery Output](https://github.com/user-attachments/assets/6bc31a89-8df1-4568-9b52-41a11926e276)


**Happy Coding! 🎉**  



