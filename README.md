# 🗑️ Lixeira Inteligente com IA

Projeto acadêmico desenvolvido utilizando Arduino, Python, Visão Computacional e Inteligência Artificial para automação e separação inteligente de resíduos recicláveis, incialmente papel e plástico.

---

# 📚 Sobre o Projeto

O projeto consiste em uma lixeira inteligente automatizada capaz de:

- Abrir automaticamente ao detectar aproximação da mão;
- Identificar resíduos recicláveis através de Inteligência Artificial;
- Abrir a tampa correta conforme o tipo de material identificado;
- Monitorar o nível de preenchimento da lixeira;
- Operar em modo automático e manual.

A proposta integra conceitos de:

- Automação
- Arduino
- Sensores
- Visão Computacional
- Inteligência Artificial
- Aprendizado Supervisionado
- Sustentabilidade

---

# 🤖 Como Funciona

1. A webcam do notebook captura a imagem do resíduo;
2. O modelo de IA identifica o tipo de material (papel, plástico, etc);
3. O sistema Python envia um comando para o Arduino;
4. O Arduino abre automaticamente a tampa correspondente;
5. LEDs indicam o nível de preenchimento da lixeira.

---

# 🧠 Inteligência Artificial

O projeto utiliza aprendizado supervisionado do tipo classificação.

O modelo será treinado utilizando imagens de resíduos recicláveis através do TensorFlow e Teachable Machine.

## Bibliotecas utilizadas

- TensorFlow
- OpenCV
- NumPy
- PySerial

---

# 🔧 Tecnologias Utilizadas

## Hardware

- Arduino
- Sensor Ultrassônico
- Servomotor
- LEDs
- Push Button
- Protoboard
- Jumpers

## Software

- Python
- Arduino IDE
- VS Code
- TensorFlow
- OpenCV
- GitHub

---

# 📂 Estrutura do Projeto

```bash
LIXEIRA-IA/
│
├── arduino/
│   └── lixeira.ino
│
├── python/
│   ├── main.py
│   ├── requirements.txt
│   │
│   └── modelo/
│       ├── keras_model.h5
│       └── labels.txt
│
├── README.md
│
├── .gitignore
│
└── venv/
```

---

# ▶️ Como Executar

## 1. Clonar repositório

```bash
git clone LINK_DO_REPOSITORIO
```

---

## 2. Criar ambiente virtual

```bash
py -3.11 -m venv venv
```

---

## 3. Ativar ambiente virtual

### Windows

```bash
venv\Scripts\activate
```

---

## 4. Instalar dependências

```bash
pip install -r python/requirements.txt
```

---

## 5. Executar projeto

```bash
python python/main.py
```

---

# 👨‍💻 Integrantes


- SAIRA AGUIAR ROCHA
- WILSON PEREIRA DE LIMA

---

# 🎯 Objetivos

- Automatizar o descarte de resíduos;
- Incentivar a coleta seletiva;
- Aplicar IA integrada ao Arduino;
- Demonstrar aplicações práticas de visão computacional;
- Desenvolver solução sustentável e interativa.

---

# 📌 Status do Projeto

🚧 Em desenvolvimento

---

# 📜 Licença

Projeto acadêmico desenvolvido para fins educacionais.