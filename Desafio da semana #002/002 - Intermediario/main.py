import os #para limpar o terminal
from conta_banco import ContaBancaria #para usar as funções da classe ContaBancaria

#função principal
def main():
    contas = []
    
    while True:
        print("\n=====================")
        print("1. Criar nova conta")
        print("2. Login")
        print("3. Sair")
        print("=====================\n")
        opcao = input("Digite o numero correspondente a opção que você deseja: ")
        os.system("cls")


        if opcao == '1':
            contas.append(ContaBancaria.criarConta())  #chama a função para adicionar nova conta
        elif opcao == '2':
            contaLogada = ContaBancaria.login(contas)  #chama a função para logar a conta
            
            if contaLogada:
                while True:
                    print("\n=====================")
                    print("1. Depositar")
                    print("2. Sacar")
                    print("3. Transferir")
                    print("4. Verificar saldo")
                    print("5. Logout")
                    print("=====================\n")
                    opcaoConta = input("Digite o numero correspondente a opção que voce deseja: ")
                    os.system("cls")
                    
                    if opcaoConta == '1':
                        valor = float(input("Digite o valor para depositar: "))
                        contaLogada.depositar(valor)  # Chamando método da instância
                    elif opcaoConta == '2':
                        valor = float(input("Digite o valor para sacar: "))
                        contaLogada.sacar(valor)  # Chamando método da instância
                        
                    elif opcaoConta == '3':
                        outraConta = ContaBancaria.loginTransferir(contas) 
                        if outraConta:
                            valor = float(input("Digite o valor para transferir: "))
                            contaLogada.transferir(outraConta, valor)  # Chamando método da instância
                            
                    elif opcaoConta == '4':
                        contaLogada.verificarSaldo()  # Chamando método da instância
                    elif opcaoConta == '5':
                        break
                    else:
                        print("\n\t--- Erro! Opção INVÁLIDA! ---\n")
        elif opcao == '3':
            break
        else: 
            print("\n\t--- Erro! Opção INVÁLIDA! ---\n")
            
if __name__ == "__main__":
    main()  