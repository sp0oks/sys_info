# sys_info
A general system information syscall project for the Linux Kernel.

## Introdução
Para este projeto implementamos a syscall sys_info(), que dependendo da opção passada no argumento pode retornar:
- OPT_UNAME(nome e versão do Kernel atual, nome do host, arquitetura do sistema)
- OPT_PID(PID e PPID do processo atual)
- OPT_UID(UID e EUID do processo atual)
- OPT_RUSAGE(Informações do tempo total de execução do processo atual e dos processos filhos)
- OPT_ALL(todas as opções acima)
Todas as informações pedidas são retornadas numa struct info_t, que pode ou não ter todos seus campos completos dependendo da opção pedida.
Para implementação do trabalho, utilizamos o Kernel Linux versão 3.17.2, e a imagem de sistema DC_SO.img fornecida em aula.

## Execução dos exemplos
Pra montar os exemplos basta executar:
```bash
cd sys_info
make all
```
## Instruções de instalação e execução

Para testar a implementação da systemcall, realizamos os seguintes passos:

1. Descompactar o arquivo **Projeto_01.zip**, que contém o kernel e a imagem do sistema e colocar os arquivos **test_info.c** e **sys_info.h** na pasta gerada.

2. Modificar o arquivo *linux-3.17.2/arch/x86/syscalls/syscall_32.tlb*, adicionando a seguinte linha ao final do arquivo:  
    `357	i386	info	sys_info`

3. Adicionar a declaração da função *sys_info* e do struct *info_t* no arquivo *linux-3.17.2/include/linux/syscalls.h*:  
    ```C
    #include <linux/utsname.h>

    typedef struct {
	struct new_utsname unameData;
	pid_t pid, ppid;
	uid_t uid, euid;
	struct rusage rusageSelf, rusageChildren;
    } info_t;
    
    asmlinkage long sys_info(int opt, info_t *buf);
    ```
4. Incluir o código **info.c** no diretório *linux-3.17.2/arch/x86/kernel/*.

5. Modificar o Makefile da pasta *linux-3.17.2/arch/x86/kernel/*, para que o nosso arquivo **info.c** seja compilado com o kernel, incluindo a linha:  
    `obj-y	+=	info.o`

6. Acessar a pasta *linux-3.17.2/* e compilar o kernel, com o comando:  
    `$ make -j 5 ARCH=i386`

7. Após isso, compilar o código de teste **test_info.c** com o comando:  
    `$ gcc -m32 -static test_info.c -o test_info`

8. Executar a máquina virtual para testar a implementação da syscall no kernel alvo, utilizando o comando:  
    `$ qemu-system-i386 -hda DC_SO.img -kernel linux-3.17.2/arch/i386/boot/bzImage -append "ro root=/dev/hda" -hdb test_info`

9. Logar no sistema com as credenciais:  
    **user:root**  
    **password:root**

10. Executar os seguintes comandos para teste da syscall:  
    ```bash
    $ cat /dev/hdb > test_info 
    $ chmod +x test_info
    $ ./test_info
    ```
## Realizado pelos alunos:
* Bianca Garcia Martins
* Gabriel de Souza Alves
* Giulia Mazzutti Teixeira
