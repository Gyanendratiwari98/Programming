import cv2

try:
    # Read the input image
    image = cv2.imread("Images/image.jpg", cv2.IMREAD_UNCHANGED )

    # Check if the image is loaded successfully
    if image is None:
        print("Error: Could not read the input image.")
    else:
        # Request user input for new dimensions
        new_width = int(input("Enter the new width you want: "))
        new_height = int(input("Enter the new height you want: "))

        # Resize the image to the new dimensions
        output = cv2.resize(image, (new_width, new_height))

        # Save the resized image
        cv2.imwrite('newImage.png', output)

        print("Resized image saved as 'newImage.png'.")

except Exception as e:
    print(f"An error occurred: {e}")
