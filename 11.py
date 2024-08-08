import cv2
import numpy as np

image = cv2.imread("/home/vikyath-rai-m-s/Desktop/cg/img4.png")
cv2.waitKey(0)

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

edged = cv2.Canny(gray, 30, 200)
cv2.waitKey(0)

contours, hierarchy = cv2.findContours(edged, cv2.RETR_CCOMP,
cv2.CHAIN_APPROX_NONE)

print("Number of Contours found = " + str(len(contours)))

cv2.drawContours(image, contours, -1, (0, 255, 0), 1)
cv2.imshow('Contours [Vikhyath Rai MS:4al21cs177]' , image)
cv2.waitKey(0)
cv2.destroyAllWindows()
