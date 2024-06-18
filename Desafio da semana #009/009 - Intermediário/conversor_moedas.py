import os
import requests

def obterTaxaCambio(chaveApi, moedaOrigem, moedaDestino):
    url = f"https://v6.exchangerate-api.com/v6/{chaveApi}/latest/{moedaOrigem}"
    response = requests.get(url)
    data = response.json()
    if data['result'] == 'success':
        return data['conversion_rates'][moedaDestino]
    else:
        raise Exception("Erro ao obter a taxa de câmbio: " + data['error-type'])

def converterMoeda(chaveApi, moedaOrigem, moedaDestino, valor):
    taxa = obterTaxaCambio(chaveApi, moedaOrigem, moedaDestino)
    return valor * taxa

def imprimirMoedas(chaveApi):
    url = f"https://v6.exchangerate-api.com/v6/{chaveApi}/codes"
    response = requests.get(url)
    data = response.json()
    moedas = data['supported_codes']
    print("Moedas suportadas:")
    for moeda in moedas:
        print(moeda)

def main():
    chaveApi = "083cf26cf6f06c5ceb000151"
    
    print("\n\t\t ----- Conversor de Moedas -----\n")

    while True:
        
        print("\n\t\t==================================")
        print("\t\t\t\tMENU\n")
        print("\t\t1 - Consultar moedas suportadas")
        print("\t\t2 - Converter valor entre moedas")
        print("\t\t3 - Sair")
        print("\t\t==================================\n")
        opcao = int(input("Escolha uma opção: "))
        os.system('cls')
        
        if opcao == 1:
            imprimirMoedas(chaveApi)
        elif opcao == 2:
            moedaOrigem = input("Digite a moeda de origem (ex: USD): ").upper()
            moedaDestino = input("Digite a moeda de destino (ex: BRL): ").upper()
            valor = float(input("Digite o valor a ser convertido: "))
            
            try:
                valorConvertido = converterMoeda(chaveApi, moedaOrigem, moedaDestino, valor)
                print(f"{valor} {moedaOrigem} é igual a {valorConvertido:.2f} {moedaDestino}")
            except Exception as e:
                print(e)
        elif opcao == 3:
            print("\n\t\tPrograma Encerrado.\n")
            break
        else:
            print("\n\t\tOpção INVÁLIDA! Tente novamente\n")

if __name__ == "__main__":
    main()
