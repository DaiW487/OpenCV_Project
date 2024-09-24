***Claim : This README.md document is written in English***

#I have successfully implemented various operations on image processing with OpenCV.

##I'll elaborate on how I built the project:
  ###1.The Use of Basic Functions
     use the basic opencv functions such as using cvtColor to shift the color space to Gray or HSV format,using Blur to filter the image and so on.
  ###2.Definite Functions to Extract the Red Area , The Contours and The Bounding Box
     For example:Extract the red area
     Step1:shift the image to Gray(using function cvtcolor)
     Step2:Binarization(using function threshold)
     Step3:fing the contours(using function findContours)
     Step4:draw the found contours(using function drawContours)
  ###3.Calculate the Area of Red area
     Just take use of function contourArea(after finding the contours)
  ###4.Basic operations to write some words,draw graphs and rotate the image
     Take use of various functions putTxet,Rotate,rectangle and circle

##When I confront bugs,I tend for GPT for help.I use GPT to solve the problem including the empty image problem.



##The following screenshots are listed to show my results , please check.

***Image color space conversion(Gray ang HSV)
![Gray and HSV](https://github.com/user-attachments/assets/c784a724-2784-4349-a77f-e97a91aac73d)
***Filtering operations
![Blur](https://github.com/user-attachments/assets/27a3f792-a1ff-4dc4-8f54-3d8363703717)
***Extract the red area
![red image](https://github.com/user-attachments/assets/c9664358-6703-4705-b4c0-978be1f7ffed)
***Find the external contours of red area
![red contour](https://github.com/user-attachments/assets/a50addef-4dbc-4929-b6a5-17ff1331ec80)
***Find the bounding box of contours
![bounding box](https://github.com/user-attachments/assets/6966c5cc-2f5f-443b-a932-cbc958f5a457)
***Calculate the area of contours
![Area](https://github.com/user-attachments/assets/1ba11138-0716-4317-894f-a4090978d72f)
***Operations including Gray Binary Dilate Erode and Flood (I only showed the Final result image that use all of operations)
![Erode and Flood](https://github.com/user-attachments/assets/8ecbd6b3-7cbe-49bb-8c0e-d0006126226d)
***Draw rectangle and circle and Write words
![rectangle circle and word](https://github.com/user-attachments/assets/faa26f58-0b46-42e1-a1cf-cfcb52cbe289)
***Rotate the image for 35 degree and Cut the image
![Rotate and Cut](https://github.com/user-attachments/assets/bee24caf-02f9-4c59-9b66-85c94664ebc6)
