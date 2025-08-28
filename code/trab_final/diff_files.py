import sys

if len(sys.argv) != 3:
    print("Uso: python compara.py arquivo1.txt arquivo2.txt")
    sys.exit(1)

file1, file2 = sys.argv[1], sys.argv[2]

with open(file1, 'r', encoding='utf-8') as f1, open(file2, 'r', encoding='utf-8') as f2:
    lines1 = f1.readlines()
    lines2 = f2.readlines()

differences = False
max_len = max(len(lines1), len(lines2))

for i in range(max_len):
    l1 = lines1[i].rstrip('\n') if i < len(lines1) else "<final do arquivo>"
    l2 = lines2[i].rstrip('\n') if i < len(lines2) else "<final do arquivo>"

    if l1 != l2:
        differences = True
        print(f'Diferença na linha {i+1}:')
        print(f'  {file1}: "{l1}"')
        print(f'  {file2}: "{l2}"')
        print()

if not differences:
    print("Os arquivos são iguais.")
else:
    print("Os arquivos são diferentes.")
