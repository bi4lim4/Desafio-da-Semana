import os  # para limpar o terminal

class Tarefa:
    indiceAtual = 1

    #Função para os parametros da tarefa
    def __init__(self, titulo, descricao, dataLimite, prioridade, status="Pendente"):
        self.indice = Tarefa.indiceAtual
        self.titulo = titulo
        self.descricao = descricao
        self.dataLimite = dataLimite
        self.prioridade = prioridade
        self.status = status
        Tarefa.indiceAtual += 1

    #Função para retornar os valores da tarefa
    def __str__(self):
        return f"\nTarefa: {self.titulo}\nDescrição: {self.descricao}\nData de Vencimento: {self.dataLimite}\nPrioridade: {self.prioridade}\nStatus: {self.status}\nIndice: {self.indice}"

#Classe para gerenciar as tarefas
class GerenciaTarefas:

    def __init__(self):
        self.tarefas = []

    #Função para criar uma tarefa
    def criarTarefa(self, titulo, descricao, dataLimite, prioridade):
        if 1 <= prioridade <= 5:
            tarefa = Tarefa(titulo, descricao, dataLimite, prioridade)
            self.tarefas.append(tarefa)
            print("Tarefa criada com SUCESSO!")
        else:
            print("INVALIDO! A prioridade precisa estar entre 1 e 5.")

    #Função para visualizar as tarefas
    def visualisarTarefa(self, filtro=None, status=None, prioridade=None, dataLimite=None):
        if filtro:
            tarefasFiltradas = [tarefa for tarefa in self.tarefas if
                                tarefa.status == filtro or tarefa.prioridade == filtro or tarefa.dataLimite == filtro]
            for tarefa in tarefasFiltradas:
                print(tarefa)
        elif status:
            if status in ["Pendente", "Concluido"]:
                tarefasFiltradas = [tarefa for tarefa in self.tarefas if tarefa.status == status]
                for tarefa in tarefasFiltradas:
                    print(tarefa)        
            else:
                print("\n\t --- Status INVÁLIDO. Use 'Pendente' ou 'Concluido' ---")
        elif prioridade:
            if 1 <= prioridade <= 5 and prioridade in [tarefa.prioridade for tarefa in self.tarefas]:
                tarefasFiltradas = [tarefa for tarefa in self.tarefas if tarefa.prioridade == prioridade]
                for tarefa in tarefasFiltradas:
                    print(tarefa)
            else:
                print("\n\t --- Prioridade fora do intervalo [1 a 5] ou inexistente! ---")
        elif dataLimite:
            if dataLimite in [tarefa.dataLimite for tarefa in self.tarefas]:
                tarefasFiltradas = [tarefa for tarefa in self.tarefas if tarefa.dataLimite == dataLimite]
                for tarefa in tarefasFiltradas:
                    print(tarefa)
            else:
                print("\n\t --- Nenhuma tarefa com essa data de vencimento ---.")
        else:
            for tarefa in self.tarefas:
                print(tarefa)
    
    #Função para modificar uma tarefa - Updade
    def modificarTarefa(self, indice, titulo=None, descricao=None, dataLimite=None, prioridade=None):
        if self.verificarIndice(indice):
            tarefa = self.tarefas[indice - 1]  
            if titulo:
                tarefa.titulo = titulo
                print("Tarefa modificada com SUCESSO!")
            if descricao:
                tarefa.descricao = descricao
                print("Tarefa modificada com SUCESSO!")
            if dataLimite:
                tarefa.dataLimite = dataLimite
                print("Tarefa modificada com SUCESSO!")
            if prioridade:
                tarefa.prioridade = prioridade
                print("Tarefa modificada com SUCESSO!")
        else:
            print("\n\t--- Índice fora da lista. ---")

    #Função para excluir uma tarefa
    def excluirTarefa(self, indice):  
        if self.verificarIndice(indice):
            del self.tarefas[indice - 1] 
        else:
            print("\n\t--- Índice fora da lista. ---")
   
    #Função para marcar uma tarefa como concluida
    def marcarTarefaConcluida(self, indice):
        if self.verificarIndice(indice):
            self.tarefas[indice - 1].status = "Concluido"  
        else:
            print("\n\t--- Índice fora da lista. ---")

    def verificarIndice(self, indice):
        return 0 < indice <= len(self.tarefas) 

#Função para exibir o menu
def menu():
    print("\n===============================")
    print("1 - Criar Tarefa")
    print("2 - Visualizar Tarefas")
    print("3 - Modificar Tarefas")
    print("4 - Excluir Tarefa")
    print("5 - Mudar Status de uma Tarefa")
    print("6 - Sair")
    print("===============================")


if __name__ == "__main__":
    gerenciaTarefas = GerenciaTarefas()

    print("\n\t\t --- PROGRAMA DE GERENCIAMENTO DE TAREFAS ---\n")
    # Adicionando tarefas de exemplo
    gerenciaTarefas.criarTarefa("Estudar Python", "Estudar classes e objetos", "2024-05-10", 3)
    gerenciaTarefas.criarTarefa("Bora vê Eclipse", "A qualquer momento...", "2024-05-05", 2)

    while True:
        menu()
        opcao = int(input("Digite a opção desejada: "))
        os.system("cls")

        if opcao == 1:
            titulo = input("Digite o título da tarefa: ")
            descricao = input("Digite a descrição da tarefa: ")
            dataLimite = input("Digite a data de vencimento da tarefa: ")
            prioridade = int(input("Digite a prioridade da tarefa [de 1 a 5]: "))
            gerenciaTarefas.criarTarefa(titulo, descricao, dataLimite, prioridade)
        elif opcao == 2:
            print("\n===============================")
            print("      VISUALIZAR TAREFAS:")
            print("1 - Exibir todas as tarefas")
            print("2 - Filtrar tarefas")
            print("===============================")
            opcao = int(input("Digite a opção desejada: "))
            os.system("cls")

            if opcao == 1:
                gerenciaTarefas.visualisarTarefa()
            elif opcao == 2:
                print("\n===============================")
                print("       FILTRAR TAREFAS:")
                print("1 - Filtrar por status")
                print("2 - Filtrar por prioridade")
                print("3 - Filtrar por data")
                print("===============================")

                opcao = int(input("Digite a opcao de filtragem: "))
                os.system("cls")
                if opcao == 1:
                    status = input("Digite o status desejado [Pendente ; Concluido]: ")
                    gerenciaTarefas.visualisarTarefa(status=status)
                elif opcao == 2:
                    prioridade = int(input("Digite a prioridade desejada [1 a 5]: "))
                    gerenciaTarefas.visualisarTarefa(prioridade=prioridade)
                elif opcao == 3:
                    dataLimite = input("Digite a data desejada: ")
                    gerenciaTarefas.visualisarTarefa(dataLimite=dataLimite)
                else:
                    print("\n\t--- Opção INVÁLIDA! ---")
            else:
                print("\n\t--- Opção INVÁLIDA! ---")
        elif opcao == 3:
            indice = int(input("Digite o indice da tarefa que deseja modificar: "))

            print("\n===============================")
            print("        MODIFICAR TAREFA:")
            print("1 - Modificar título")
            print("2 - Modificar descrição")
            print("3 - Modificar data")
            print("4 - Modificar prioridade")
            print("===============================")
            opcao = int(input("Digite a opção que deseja modificar: "))
            os.system("cls")

            if opcao == 1:
                titulo = input("Digite o novo título da tarefa: ")
                gerenciaTarefas.modificarTarefa(indice, titulo=titulo)
            elif opcao == 2:
                descricao = input("Digite a nova descrição da tarefa: ")
                gerenciaTarefas.modificarTarefa(indice, descricao=descricao)
            elif opcao == 3:
                dataLimite = input("Digite a nova data da tarefa: ")
                gerenciaTarefas.modificarTarefa(indice, dataLimite=dataLimite)
            elif opcao == 4:
                prioridade = int(input("Digite a nova prioridade da tarefa: "))
                gerenciaTarefas.modificarTarefa(indice, prioridade=prioridade)
            else:
                print("\n\t--- Opção INVÁLIDA! ---")
        elif opcao == 4:
            indice = int(input("Digite o indice da tarefa que deseja excluir: "))
            gerenciaTarefas.excluirTarefa(indice)  # Correção de nome aqui
            print("Tarefa excluída com SUCESSO!")
        elif opcao == 5:
            indice = int(input("Digite o indice da tarefa que deseja marcar como concluída: "))
            gerenciaTarefas.marcarTarefaConcluida(indice)
            print("Tarefa marcada como CONCLUÍDA com SUCESSO!")
        elif opcao == 6:
            break
        else:
            print("\n\t--- Opção INVÁLIDA! ---")
