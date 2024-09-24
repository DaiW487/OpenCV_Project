# ***Claim : This README.md document is written in English***
## I'll elaborate on how I built the project:  

  &emsp;1.The Use of Basic Functions  
    &emsp;&emsp; use the basic opencv functions such as using cvtColor to shift the color space to Gray or HSV format,using Blur to filter the image and so on.  
     
  &emsp;2.Definite Functions to Extract the Red Area , The Contours and The Bounding Box  
   &emsp; &emsp;For example:Extract the red area  
    &emsp;&emsp; Step1:shift the image to Gray(using function cvtcolor)  
    &emsp;&emsp; Step2:Binarization(using function threshold)  
   &emsp; &emsp; Step3:fing the contours(using function findContours)  
    &emsp;&emsp; Step4:draw the found contours(using function drawContours)  
     
 &emsp; 3.Calculate the Area of Red area  
    &emsp; &emsp;Just take use of function contourArea(after finding the contours)  
     
 &emsp; 4.Basic operations to write some words,draw graphs and rotate the image  
   &emsp; &emsp; Take use of various functions putTxet,Rotate,rectangle and circle     


       
## When I confront bugs,I tend for GPT for help.I use GPT to solve the problem including the empty image problem and some other bugs.   

![2024-09-24 10-55-10屏幕截图](https://github.com/user-attachments/assets/1bdd1a98-716d-4080-bd05-1e1fbd9f1e95)
![2024-09-24 11-19-46屏幕截图](https://github.com/user-attachments/assets/5104e0cf-a076-4ea1-ae56-5fbd00488fde)



  

            
## The following screenshots are listed to show my results , please check.  

&emsp;***Image color space conversion(Gray ang HSV)***
![Gray and HSV](https://github.com/user-attachments/assets/c784a724-2784-4349-a77f-e97a91aac73d)
&emsp;***Filtering operations***
![Blur](https://github.com/user-attachments/assets/27a3f792-a1ff-4dc4-8f54-3d8363703717)
&emsp;***Extract the red area***
![red image](https://github.com/user-attachments/assets/c9664358-6703-4705-b4c0-978be1f7ffed)
&emsp;***Find the external contours of red area***
![red contour](https://github.com/user-attachments/assets/a50addef-4dbc-4929-b6a5-17ff1331ec80)
&emsp;***Find the bounding box of contours***
![bounding box](https://github.com/user-attachments/assets/6966c5cc-2f5f-443b-a932-cbc958f5a457)
&emsp;***Calculate the area of contours***
![Area](https://github.com/user-attachments/assets/1ba11138-0716-4317-894f-a4090978d72f)
&emsp;***Operations including Gray Binary Dilate Erode and Flood (I only showed the Final result image that use all of operations)***
![Erode and Flood](https://github.com/user-attachments/assets/8ecbd6b3-7cbe-49bb-8c0e-d0006126226d)
&emsp;***Draw rectangle and circle and Write words***
![rectangle circle and word](https://github.com/user-attachments/assets/faa26f58-0b46-42e1-a1cf-cfcb52cbe289)
&emsp;***Rotate the image for 35 degree and Cut the image***
![Rotate and Cut](https://github.com/user-attachments/assets/bee24caf-02f9-4c59-9b66-85c94664ebc6)
