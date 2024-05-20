import face_recognition
import cv2
import numpy as np
import csv
from datetime import datetime

# Load the webcam
video_capture = cv2.VideoCapture(0)

# Load images and encode faces
gyanendras_image = face_recognition.load_image_file("faces/gyanendra.jpg")
gyanendra_encodings = face_recognition.face_encodings(gyanendras_image)[0]

anmols_image = face_recognition.load_image_file("faces/anmol.jpg")
anmol_encodings = face_recognition.face_encodings(anmols_image)[0]

# Create arrays for known face encodings and names
known_face_encodings = [gyanendra_encodings, anmol_encodings]
known_face_names = ["Gyanendra", "Anmol"]

# Create a list of students
students = known_face_names.copy()

# Get the current date and create/open a CSV file
now = datetime.now()
current_date = now.strftime("%d-%m-%Y")
f = open(f"{current_date}.csv", "w+", newline="")
lnwrite = csv.writer(f)

# Main loop for face recognition
while True:
    _, frame = video_capture.read()
    small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
    rgb_small_frame = cv2.cvtColor(small_frame, cv2.COLOR_BGR2RGB)

    # Detect face locations and encodings
    face_locations = face_recognition.face_locations(rgb_small_frame)
    face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

    # Iterate through each face detected
    for face_encoding in face_encodings:
        # Compare face encodings with known face encodings
        match = face_recognition.compare_faces(known_face_encodings, face_encoding)
        face_distance = face_recognition.face_distance(known_face_encodings, face_encoding)
        best_match_index = np.argmin(face_distance)

        if match[best_match_index]:
            name = known_face_names[best_match_index]
            # If the recognized face is a student, mark as present
            if name in students:
                font = cv2.FONT_HERSHEY_SIMPLEX
                bottom_left_corner_of_text = (10, 100)
                font_scale = 1.5
                font_color = (255, 0, 0)
                thickness = 2
                line_type = 2
                cv2.putText(frame, name + " Present", bottom_left_corner_of_text, font, font_scale, font_color, thickness, line_type)
                # Remove the student from the list of students
                students.remove(name)
                # Get current time and write to CSV
                current_time = now.strftime("%H-%m-%S")
                lnwrite.writerow([name, current_time])

    # Display the frame with attendance information
    cv2.imshow("Attendance", frame)
    # Press 'q' to exit the loop
    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

# Release video capture and close all windows
video_capture.release()
cv2.destroyAllWindows()
# Close the CSV file
f.close()
