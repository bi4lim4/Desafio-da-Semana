import string
import random

def gerarSenha(numeroCaracteres):
    caracteres = string.ascii_letters + string.digits  + string.punctuation 
    senha = ''.join(random.choice(caracteres) for i in range(numeroCaracteres))
    return senha

print("\n\t\t===== GERADOR DE SENHAS =====")

numeroCaracteres = 0
while numeroCaracteres < 8 or numeroCaracteres > 18:
    numeroCaracteres = int(input('Digite o numero de caracteres da senha [minimo 8]: '))

    if numeroCaracteres < 8 or numeroCaracteres > 18:
        print('\n---- Numero de caracteres INVALIDO! Por favor, digite um numero entre 8 e 18 ----\n')

quantidadeSenhas = int(input('Quantas senhas deseja gerar com esse numero de caracteres?: '))

print("\n")
for i in range(quantidadeSenhas):
    print(f"Senha {i+1}: {gerarSenha(numeroCaracteres)}")