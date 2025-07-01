import sys
import random

def main():
    if len(sys.argv) < 2:
        print("Uso: python programa.py <quantidade> [i|f|if|fi] [intervalo_inicial] [intervalo_final] [numero_vetores]")
        sys.exit(1)

    try:
        quantidade = int(sys.argv[1])
        if quantidade <= 0:
            raise ValueError
    except ValueError:
        print("O argumento <quantidade> deve ser um inteiro positivo.")
        sys.exit(1)

    # Tipo de valor ('i' ou 'f')
    tipo = sys.argv[2].lower() if len(sys.argv) > 2 else 'i'

    # Intervalo inicial e final
    try:
        intervalo_inicial = float(sys.argv[3]) if len(sys.argv) > 3 else 0
        intervalo_final = float(sys.argv[4]) if len(sys.argv) > 4 else 100
        if intervalo_inicial > intervalo_final:
            raise ValueError
    except ValueError:
        print("Os argumentos de intervalo devem ser números e o inicial deve ser menor ou igual ao final.")
        sys.exit(1)

    # Numero de vetores a serem criados
    try:
        numero_vetores = int(sys.argv[5]) if len(sys.argv) > 5 else 1
        if numero_vetores <= 0:
            raise ValueError
    except ValueError:
        print("O argumento [numero_vetores] deve ser um inteiro positivo.")
        sys.exit(1)

    valores = []
    for _ in range(numero_vetores):
        if tipo == 'f':
            for _ in range(quantidade):
                valor = random.uniform(intervalo_inicial, intervalo_final)
                valores.append(valor)
        elif tipo == 'if':
            for i in range(quantidade):
                if (i % 2 == 0):
                    valor = random.randint(int(intervalo_inicial), int(intervalo_final))
                    valores.append(valor)
                else:
                    valor = random.uniform(intervalo_inicial, intervalo_final)
                    valores.append(valor)
        elif tipo == 'fi':
            for i in range(quantidade):
                if (i % 2 == 0):
                    valor = random.uniform(intervalo_inicial, intervalo_final)
                    valores.append(valor)
                else:
                    valor = random.randint(int(intervalo_inicial), int(intervalo_final))
                    valores.append(valor)
        else:
            for _ in range(quantidade):
                valor = random.randint(int(intervalo_inicial), int(intervalo_final))
                valores.append(valor)

    cont = 0
    for valor in valores:
       
        if tipo == 'f':
            print(f"{valor:.2f}")
        elif tipo == 'if':
            if cont % 2 == 0:
                print(valor)
            else:
                print(f"{valor:.2f}")
            cont += 1
        elif tipo == 'fi':
            if cont % 2 == 0:
                print(f"{valor:.2f}")
            else:
                print(valor)
            cont += 1
        else:
            print(valor)

if __name__ == "__main__":
    main()