import cv2

# Abrir webcam
camera = cv2.VideoCapture(0)

while True:
    # Capturar frame da câmera
    ret, frame = camera.read()

    # Mostrar webcam na tela
    cv2.imshow("Webcam da Lixeira IA", frame)

    # Apertar ESC para sair
    if cv2.waitKey(1) == 27:
        break

# Fechar câmera
camera.release()
cv2.destroyAllWindows()