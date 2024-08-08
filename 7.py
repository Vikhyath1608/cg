import cv2
img = cv2.imread("/home/vikyath-rai-m-s/Desktop/cg/img1.jpg")


h, w, channels = img.shape
print(h)
print(w)
print(channels)
w_half = w//2
h_half = h//2
left_top_part = img[:h_half, :w_half]

right_top_part = img[:h_half, w_half:]


cv2.imshow('Left Top part [ Vikhyath Rai MS: 4AL21CS177]', left_top_part)
cv2.imshow('Right Top part', right_top_part)

left_bottom_part = img[h_half:, :w_half]
right_bottom_part = img[h_half:,w_half:]
cv2.imshow('left_bottom_part', left_bottom_part)
cv2.imshow('right_bottom_part', right_bottom_part)

cv2.imwrite('left_top_part.jpg', left_top_part)
cv2.imwrite('right_top_part.jpg', right_top_part)
cv2.imwrite('left_bottom_part.jpg', left_bottom_part)
cv2.imwrite('right_bottom_part.jpg', right_bottom_part)
cv2.waitKey(0)
