def encontrar_numeros_faltantes(sequencia):
    # Encontra o maior número na sequência para determinar o valor de N
    N = max(sequencia)
    
    # Gera a sequência completa de 1 a N
    sequencia_completa = list(range(1, N + 1))
    
    # Converte a lista original em um conjunto para facilitar a identificação dos números faltantes
    conjunto_original = set(sequencia)
    
    # Encontra os números que estão faltando na sequência original
    numeros_faltantes = [num for num in sequencia_completa if num not in conjunto_original]
    
    # Adiciona os números faltantes na sequência original
    for num in numeros_faltantes:
        sequencia.append(num)
    
    # Ordena a sequência resultante
    sequencia.sort()
    
    return sequencia


entrada1 = [1, 2, 4, 5]
entrada2 = [2, 4, 8, 10]

print("Entrada: ", entrada1)
saida1 = encontrar_numeros_faltantes(entrada1)
print("Saída: ", saida1)

print("Entrada: ", entrada2)
saida2 = encontrar_numeros_faltantes(entrada2)
print("Saída: ", saida2)
