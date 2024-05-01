import random

with open("cidadesBrasil.txt", "r", encoding="utf-8") as file: 
    allText = file.read() 
    words = list(map(str, allText.split("\n"))) # Dividindo o texto por quebra de linha
    

def escolher_palavra():
    return random.choice(words).upper()

def exibir_palavra(palavra, letras_corretas):
    # Mostra a palavra com as letras adivinhadas preenchidas e os espaços em branco para as letras não adivinhadas
    exibicao = ""
    for letra in palavra:
        if letra in letras_corretas:
            exibicao += letra + " "
        else:
            exibicao += "_ "
    return exibicao.strip()

def jogar_forca():
    palavra = escolher_palavra()
    letras_corretas = set()
    tentativas = 6

    print("==================================================")
    print("\tBEM-VINDO AO JOGO DA FORCA!")
    print("Tente adivinhar a palavra. Você tem 6 tentativas.")
    print("==================================================")
    print("Dica: A palavra é uma cidade brasileira\n")

    print(exibir_palavra(palavra, letras_corretas))

    while tentativas > 0:
        palpite = input("\nDigite uma letra ou a palavra completa: ").upper()

        if len(palpite) == 1:  # Se o palpite for uma letra
            if palpite in palavra:
                letras_corretas.add(palpite)
                print("Letra correta!")
            else:
                tentativas -= 1
                print("Letra incorreta. Você tem {} tentativas restantes.".format(tentativas))
        elif len(palpite) == len(palavra.replace(" ", "")) and palpite.isalpha():  # Se o palpite for a palavra completa
            if palpite.upper() == palavra.replace(" ", "").upper():
                print("\n=================================================================")
                print("\nPARABÉNS! Você adivinhou a palavra corretamente: '{}'".format(palavra))
                break
            else:
                tentativas -= 1
                print("Palavra incorreta. Você tem {} tentativas restantes.".format(tentativas))
        else:
            print("Por favor, insira apenas uma letra ou a palavra completa.")

        print(exibir_palavra(palavra, letras_corretas))

    if tentativas == 0:
        print("\n=============================================================")
        print("\nVOCÊ PERDEU! A palavra correta era '{}'.".format(palavra))
        print("Mais sorte na próxima vez! ;)")

jogar_forca()