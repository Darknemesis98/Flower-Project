import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library
from time import sleep # Import the sleep function from the time module
import cv2
import numpy as np
import sys
k=0
GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW) # Set pin 8 to be an output pin and set initial value to low (off)
GPIO.setup(16, GPIO.OUT, initial=GPIO.LOW)
facePath = "haarcascade_frontalface_default.xml"
smilePath = "haarcascade_smile.xml"
faceCascade = cv2.CascadeClassifier(facePath)
smileCascade = cv2.CascadeClassifier(smilePath)

cap = cv2.VideoCapture(0)
cap.set(3,500)
cap.set(4,375)
cap.set(cv2.cv.CV_CAP_PROP_FPS,20)
sF = 1.2
print(" Welcome to smile detection project")
while True:

    ret, frame = cap.read() # Capture frame-by-frame
    img = frame
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor= sF,
        minNeighbors=5,
        minSize=(20, 20),
        flags=cv2.CASCADE_SCALE_IMAGE
    )
    # ---- Draw a rectangle around the faces

    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 200, 255), 2)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = frame[y:y+h, x:x+w]
        print("faces= ", faces)
        GPIO.output(16,GPIO.HIGH)
        if faces[0]==0:
           GPIO.output(16,GPIO.LOW)
        
        smile = smileCascade.detectMultiScale(
            roi_gray,
            scaleFactor= 1.7,
            minNeighbors=15,
            minSize=(25, 25),
            flags=cv2.CASCADE_SCALE_IMAGE
            )
   # return smile
        # Set region of interest for smiles
        for (x, y, w, h) in smile:
            print ("Found"), len(smile), ("smiles!")
            print ("Smile = ",smile)
            cv2.rectangle(roi_color, (x, y), (x+w, y+h), (255, 0, 0), 1)
            GPIO.output(8, GPIO.HIGH)
        if len(smile)<1: 
           GPIO.output(8, GPIO.LOW)
    cv2.imshow('Smile Detector', frame)
    c = cv2.waitKey(7) % 0x100
    if c == 27:
        break
    faces=0    
cap.release()
cv2.destroyAllWindows()
