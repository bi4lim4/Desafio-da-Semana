import os  # para limpar o terminal
from gerencia_tarefas import Tarefa, menu
from gerencia_tarefas import GerenciaTarefas  # para usar as funções da classe GerenciaTarefas

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
