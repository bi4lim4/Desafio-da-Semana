class ContaBancaria:
    numContaAtual = 1
    
    #atributos de conta bancária
    def __init__(self, senha, saldo=0):
        self.numeroConta = ContaBancaria.numContaAtual
        self.senha = senha
        self.saldo = saldo
        ContaBancaria.numContaAtual += 1 #Incrementa o número da conta
        
    #retorna o numero da conta do usuario
    def obterNumeroConta(self):
        return self.numeroConta    
    
    #função para depositar dinheiro
    def depositar(self, valor):
        self.saldo += valor
        print("Depósito de", valor, "realizado com SUCESSO!")
     
    #função para sacar dinheiro
    def sacar(self, valor):
        if valor <= self.saldo:
            self.saldo -= valor
            print("\n|Saque de", valor, "realizado com SUCESSO!|")
        else:
            print("\n\t|Saldo INSUFICIENTE!!|\n")
            
    #função para transferir dinheiro       
    def transferir(self, outraConta, valor):
        if valor <= self.saldo:
            self.saldo -= valor
            outraConta.saldo += valor
            print("\n|Transferência de", valor, "realizada com sucesso!|")
        else:
            print("\n\t|Saldo INSUFICIENTE para a transferência!!|\n")
            
    #função para verificar o saldo da conta
    def verificarSaldo(self):
        print("\nSaldo atual: ", self.saldo)    
            
    #função para criar uma nova conta
    @staticmethod
    def criarConta():
        senha = input("Crie uma senha para a conta: ")
        saldoInicial = float(input("Digite o saldo inicial da conta: "))
        novaConta = ContaBancaria(senha, saldoInicial)
        print("\n|Conta criada com sucesso!|")
        print("\n|O número da sua conta é: ", novaConta.obterNumeroConta())
        return novaConta
    
    
    #função para realizar login em uma conta existente
    @staticmethod
    def login(contas):
        numeroConta = int(input("Digite o número da conta: "))
        senha = input("Digite a senha da conta: ")
        
        for conta in contas:
            if conta.numeroConta == numeroConta and conta.senha == senha:
                return conta
        print("\n\t--- Número da conta ou senha INCORRETOS ---\n")
        return None
    @staticmethod

    #função que permite transferir dinheiro para outra conta
    def loginTransferir(contas):
        numeroConta = int(input("Digite o número da conta a qual deseja transferir: "))
        senha = input("Digite a sua senha: ")
    
        # Verifica se o número da conta digitado é maior que a quantidade de contas na lista
        if numeroConta > len(contas):
            print("\n\t--- Número de conta INVÁLIDO! ---\n")
            return None
    
        # Verifica se a senha está correta
        for conta in contas:
            if conta.senha == senha:
                # Procura a conta de destino usando o número da conta
                for outraConta in contas:
                    if outraConta.numeroConta == numeroConta:
                        return outraConta
            
                print("\n\t--- Conta de destino NÃO encontrada ---\n")
                return None
    
        print("\n\t--- Senha INCORRETA! ---\n")
        return None