#include <stdio.h>
#include <string.h>
#include <locale.h>

char login();
void editcpf();
void cadastrovenda();
void listavendas();
void balanco();
void menuvalor();
void registrors();
void listars();
void cadastrofunc();
void listfunc();
void editfunc();

struct Vendas{
	int queijo;
	int sabor;
	int doce;
	float valor;
}venda[100];

struct Recsug{
	char tipo[15];
	char nome [20];
	char texto [100];
}recsug[100];

struct Funcionarios{
	char nome[50];
	float salario;
	char sexo;
	int cod;
}funcionario[100];

//Varii�veis globais de controle dos valores das fichas
float valorq = 1,valors = 2,valord = 2.5;
//Vari�veis globais de controle do n�mero de Vendas, Reclama��es e Sugest�es, e Funcion�rios cadastrados
int vendanum = 0,recnum=0,funcnum=0;
//M�dulo do Menu Principal
int main(){
	setlocale(LC_ALL,"Portuguese");
	char tipo=login();
	char exit;
	int sl =0,ct=0,ct2=0,err=0,s=0;
	do{
		if(err==1){
			printf("\nApenas administradores t�m acesso a essa fun��o.\n");
			err=0;
		}
		printf("----------------------\n");
		printf("   SISTEMA UNIPIZZA");
		printf("\n----------------------\n\n");
		printf("\nSelecione a Opera��o");
		printf("\n\n1 = Realiza��o de Pedido:");
		printf("\n2 = Reclama��o/Sugest�o");
		printf("\n3 = Cadastro de Funcion�rios");
		printf("\n4 = Menu de Finan�as ");
		printf("\n5 = Sair\n\n---> ");
		scanf("%d",&sl);
		switch(sl){
			case 1 :
				system("cls");
				ct2=0;
				do{
					printf("\n|| Menu de Vendas || ");
					printf("\n\n1 = Realizar Venda");
					printf("\n2 = Ver �ltimas vendas");
					printf("\n3 = Voltar\n\n----> ");
					scanf("%d",&sl);
					switch(sl){
						case 1 :
							system("cls");
							cadastrovenda();
							
							break;
						case 2 :
							system("cls");
							listavendas();
							break;
						case 3 :
							system("cls");
							ct2=1;
							break;
						default:
							system("cls");
							printf("\nDigite um n�mero de 1 a 3!\n");
					}
				}while(ct2==0);
				if(sl==3){
					ct=0;
				}
				else{
					ct=0;
				}
				break;
			case 2 :
				system("cls");
				ct2=0;
				do{
					printf("\n|| Menu de Reclama��es e Sugest�es || ");
					printf("\n\n1 = Registrar Reclama��o ou Sugest�o");
					printf("\n2 = Ver �ltimas Reclama��es e Sugest�es");
					printf("\n3 = Voltar\n\n----> ");
					scanf("%d",&sl);
					switch(sl){
						case 1 :
							system("cls");
							registrors();
							break;
						case 2 :
							system("cls");
							printf("\nEscolheu op��o 2\n");
							listars();
							break;
						case 3 :
							system("cls");
							ct2=1;
							break;
						default:
							system("cls");
							printf("\nDigite um n�mero de 1 a 3!\n");
					}
				}while(ct2==0);
				if(sl==3){
					ct=0;
				}
				else{
					ct=1;
				}
				break;
			case 3 :
				if(tipo=='n'){
					system("cls");
					err=1;
					break;
				}
				system("cls");
				ct2=0;
				do{
					printf("\n|| Menu de Funcion�rios  || ");
					printf("\n\n1 = Cadastrar Funcion�rios");
					printf("\n2 = Editar Funcion�rios");
					printf("\n3 = Lista de Funcion�rios");
					printf("\n4 = Voltar\n\n----> ");
					scanf("%d",&sl);
					switch(sl){
						case 1 :
							system("cls");
							cadastrofunc();
							break;
						case 2 :
							system("cls");
							editfunc();
							break;
						case 3 :
							system("cls");
							listfunc();
							break;
						case 4 :
							system("cls");
							ct2=1;
							break;
						default:
							system("cls");
							printf("\nDigite um n�mero de 1 a 4!\n");
					}
				}while(ct2==0);
				if(sl==4){
					ct=0;
				}
				else{
					ct=1;
				}
				break;
			case 4 :
				if(tipo=='n'){
					system("cls");
					err=1;
					break;
				}
				system("cls");
				ct2=0;
				do{
					printf("\n|| Menu de Finan�as  || ");
					printf("\n\n1 = Ver balan�o di�rio");
					printf("\n2 = Editar Valores");
					printf("\n3 = Voltar\n\n----> ");
					scanf("%d",&sl);
					switch(sl){
						case 1 :
							system("cls");
							balanco();
							break;
						case 2 :
							system("cls");
							menuvalor();
							break;
						case 3 :
							system("cls");
							ct2=1;
							break;
						default:
							system("cls");
							printf("\nDigite um n�mero de 1 a 3!\n");
					}
				}while(ct2==0);
				if(sl==4){
					ct=0;
				}
				else{
					ct=0;
				}
				break;
			case 5 :
				system("cls");
				do{
					printf("Deseja realmente sair (s/n): ");
					scanf(" %c",&exit);
					if(exit=='s'){
						return 0;
					}
					else if(exit=='n'){
						system("cls");
						break;
					}
					else{
						system("cls");
					}
				}while(s==0);
				break;
			default:
				system("cls");
				printf("Digite um n�mero de 1 a 5!");
		}
	}while(ct==0);
	return 0;
}
//M�dulo de login, retorna uma vari�vel que indica o tipo de usu�rio
char login(){
	int tries=0;
	int loginef=0;
	char usertype;
	char login [50];
	char pass [50];
	char useradm [50] = "admin";
	char passadm [50] = "adm123lg";
	char usernor [50] = "user";
	char passnor [50] = "user123lg";
	do{
		printf("\nDigite o usu�rio: ");
		scanf("%s",&login);
		printf("\nDigite a senha: ");
		scanf("%s",&pass);
		if(strcmp(useradm,login)==0 && strcmp(passadm,pass)==0){
			usertype='a';
			loginef=1;
			system("cls");
		}
		else if(strcmp(login,usernor)==0 && strcmp(pass,passnor)==0){
			usertype='n';
			loginef=1;
			system("cls");
		}
		else{
			system("cls");
			printf("\nCredenciais Incorretas, tente novamente.\n");
		}
	}while(loginef==0);
	return usertype;
}
//M�dulo de Cadastro de Vendas no struct de vendas
void cadastrovenda(){
	int repeat=0;
	do{	
		float nq=0,ns=0,nd=0,cpfd=0,n=0;
		char sn;
		system("cls");
		printf("\n|| Realizar Venda ||\n");
		printf("\n\nDigite o n�mero de fatias de Queijo: ");
		scanf("%f",&nq);
		printf("Digite o n�mero de fatias de Sabores: ");
		scanf("%f",&ns);
		printf("Digite o n�mero de fatias de Doce: ");
		scanf("%f",&nd);
		venda[vendanum].queijo=nq;
		venda[vendanum].sabor=ns;
		venda[vendanum].doce=nd;
		venda[vendanum].valor=nq*valorq+ns*valors+nd*valord;
		vendanum++;
		system("cls");
		do{
			printf("Venda realizada com sucesso!\nValor total: %.2fR$\n",venda[vendanum-1].valor);
			printf("Deseja realizar outra venda agora? (s/n)");
			scanf(" %c",&sn);
			if(sn == 's'){
				n=1;
				system("cls");
			}
			else if(sn == 'n'){
				n=1;
				repeat=1;
				system("cls");
			}
			else{
				
			}
		}while(n==0);
	}while(repeat==0);
}
//M�dulo da lista de Vendas
void listavendas(){
	int i=0;
	system("cls");
	printf("\t   || Vendas do Dia ||\n");
	printf("\n|N�mero | Queijo | Sabores | Doce |  Total|\n");
	for(i=0;i<vendanum;i++){
		printf("|%-7d| %-6d | %-7d | %-5d| %6.2f|\n",i+1,venda[i].queijo,venda[i].sabor,venda[i].doce,venda[i].valor);
	}
	system("pause");
	system("cls");	
}
//M�dulo do balan�o di�rio
void balanco(){
	int i=0,tq=0,ts=0,td=0;
	float total=0;
	
	system("cls");
	printf("|| Arrecada��o Total do Dia ||\n\n");
	for(i=0;i<vendanum;i++){
		tq=tq+venda[i].queijo;
		ts=ts+venda[i].sabor;
		td=td+venda[i].doce;
		total=total+venda[i].valor;
	}
	printf("Total de fatias vendidas: %d\n",tq+ts+td);
	printf("Total de fatias de Queijo: %d\n",tq);
	printf("Total de fatias de Sabores: %d\n",ts);
	printf("Total de fatias de Doce: %d\n",td);
	printf("Valorm Total de Vendas: %.2fR$\n",total);
	system("pause");
	system("cls");
}
//M�dulo de altera��o dos valores das fichas
void menuvalor(){
	int sl=0,du=0;
	do{
		system("cls");
		printf("|| Menu de Valores ||");
		printf("\n\nValores Atuais:\n\nQueijo: %.2f\tSabores: %.2f\tDoce: %.2f",valorq,valors,valord);
		printf("\n\n1 = Alterar Valores\n2 = Voltar\n\n---->");
		scanf("%d",&sl);
		switch(sl){
			case 1 :
				system("cls");
				printf("\nDigite o valor da fatia de Queijo: ");
				scanf("%f",&valorq);
				printf("\nO valor da fatia de Queijo agora �: %.2f\n",valorq);
				printf("\nDigite o valor da fatia de Sabores: ");
				scanf("%f",&valors);
				printf("\nO valor da fatia de Sabores agora �: %.2f\n",valors);
				printf("\nDigite o valor da fatia de Doce: ");
				scanf("%f",&valord);
				printf("\nO valor da fatia de Doce agora �: %.2f\n\n",valord);
				system("pause");
				system("cls");
				break;
			case 2 :
				system("cls");
				du=1;
				break;
			default:
				system("cls");
		}
	}while(du==0);
}
//M�dulo de Registro de reclam��es e sugest�es
void registrors(){
	int sl=0,du=0,du2=0,txtvalid=0;
	do{
		printf("|| Registrar REC/SUG ||\n\n");
		printf("1 = Reclama��o\n2 = Sugest�o\n3 = Voltar\n\n---->");
		scanf("%d",&sl);
		if(sl==1){
			system("cls");
			strcpy(recsug[recnum].tipo,"Reclama��o");
			printf("\nInsira o primeiro nome do cliente: ");
			scanf("%s",&recsug[recnum].nome);
			recsug[recnum].nome[0]=toupper(recsug[recnum].nome[0]);
			printf("\nInsira a Reclama��o do cliente (M�ximo de 50 caract�res).\n\n");
			scanf(" %[^\n]s",&recsug[recnum].texto);
			printf("Reclama��o realizada com sucesso!\n");
			recnum++;
			system("pause");
			system("cls");
		}
		else if(sl==2){
			system("cls");
			strcpy(recsug[recnum].tipo,"Sugest�o");
			printf("\nInsira o primeiro nome do cliente: ");
			scanf("%s",&recsug[recnum].nome);
			recsug[recnum].nome[0]=toupper(recsug[recnum].nome[0]);
			printf("\nInsira a Sugest�o do cliente (M�ximo de 50 caract�res).\n\n");
			scanf(" %[^\n]s",&recsug[recnum].texto);
			printf("Sugest�o realizada com sucesso!\n");
			recnum++;
			system("pause");
			system("cls");
		}
		else if(sl==3){
			system("cls");
			du=1;
		}
		else{
			system("cls");
		}
	}while(du==0);
}
//M�dulo da lista de reclama��es e sugest�es
void listars(){
	int i=0;
	system("cls");
	printf("|| Reclama��es e Sugest�es do Dia ||\n\n");
	for(i=0;i<recnum;i++){
		printf("|%-14s|Nome:\t%12s|\n%s\n\n",recsug[i].tipo,recsug[i].nome,recsug[i].texto);
	}
	system("pause");
	system("cls");
}
//M�dulo de cadastro de funcion�rios
void cadastrofunc(){
	float sal=0;
	char nome[20];
	char first[20];
	char mid[20];
	char last[20];
	char nomeconv[20];
	char sexo,sn;
	int n=0,repeat=0,sexvalid=0;
	do{
		memset(nome, '\0', sizeof nome);
		memset(first, '\0', sizeof first);
		memset(mid, '\0', sizeof mid);
		memset(last, '\0', sizeof last);
		memset(nomeconv, '\0', sizeof nomeconv);
		system("cls");
		printf("\n|| Cadastrar Funcion�rio ||\n");
		int i=0,j=0,pesp=0,uesp=0;
		printf("\n\nDigite o nome do funcion�rio: ");
		scanf(" %[^\n]s",&nome);
		int len = strlen(nome);
		nome[0] = toupper(nome[0]);
		for(i=0;i<len;i++){
			if(nome[i]==' '){
				nome[i+1]=toupper(nome[i+1]);
			}
		}
		for(i=0;i<len;i++){
			if(nome[i]==' '){
				pesp=i;
				i=len+1;
			}
		}
		for(i=0;i<pesp;i++){
			first[i]=nome[i];
		}
		for(i=0;i<len;i++){
			if(nome[i]==' '){
				uesp=i;
			}
		}
		for(i=uesp,j=0;i<len;i++,j++){
			last[j]=nome[i];
		}
			for(i=pesp,j=0;i<uesp;i++){
			if(nome[i]==' '){
				mid[j] = nome[i];
				mid[j+1]=nome[i+1];
				mid[j+2]='.';
				j=j+3;
			}
		}
		strcpy(nomeconv,first);
		strcat(nomeconv,mid);
		strcat(nomeconv,last);
		strcpy(funcionario[funcnum].nome,nomeconv);
		//printf("\n%s\n",nomeconv);
		system("cls");
		do{
			printf("\nDigite o Sexo do Funcion�rio (m/f): ");
			scanf(" %c",&sexo);
			if(sexo =='m' || sexo=='f'){
				funcionario[funcnum].sexo=sexo;
				sexvalid=1;
				system("cls");
			}
			else{
				system("cls");
			}
		}while(sexvalid==0);
		printf("Digite o sal�rio do funcion�rio: ");
		scanf("%f",&sal);
		funcionario[funcnum].salario=sal;
		funcnum++;
		funcionario[funcnum].cod=funcnum;
		system("cls");
		do{
			printf("Usu�rio cadastrado com sucesso.\n\nNome: %s\nSexo: %c\nSal�rio: %.2f\nC�digo: %d",funcionario[funcnum-1].nome,funcionario[funcnum-1].sexo,funcionario[funcnum-1].salario,funcionario[funcnum].cod);
			printf("\n\nDeseja cadastrar outro funcion�rio agora? (s/n)");
			scanf(" %c",&sn);
			if(sn == 's'){
				n=1;
				system("cls");
			}
			else if(sn == 'n'){
				n=1;
				repeat=1;
				system("cls");
			}
			else{
				
			}
		}while(n==0);
	}while(repeat==0);
}
//M�dulo de edi��o de dados de funcion�rio
void editfunc(){
		float sal=0;
	char nome[20];
	char first[20];
	char mid[20];
	char last[20];
	char nomeconv[20];
	char sexo,sn;
	int n=0,repeat=0,sexvalid=0,cod=0,du=0;
		system("cls");
		printf("\n|| Editar Funcion�rio ||\n\n");
		int i=0,j=0,pesp=0,uesp=0;
		do{
			memset(nome, '\0', sizeof nome);
			memset(first, '\0', sizeof first);
			memset(mid, '\0', sizeof mid);
			memset(last, '\0', sizeof last);
			memset(nomeconv, '\0', sizeof nomeconv);
			printf("Digite o c�digo do Funcion�rio: ");
			scanf("%d",&cod);
			if(cod<=funcnum+1 && cod>0){
				du=1;
				system("cls");
			}
			else{
				printf("Funcin�rio n�o encontrado!\n");
			}
		}while(du==0);
		printf("Dados atuais\n\nNome: %s\nSexo: %c\nSal�rio: %.2f\n",funcionario[cod-1].nome,funcionario[cod-1].sexo,funcionario[cod-1].salario);
		printf("\n\nDigite o nome do funcion�rio: ");
		scanf(" %[^\n]s",&nome);
		int len = strlen(nome);
		nome[0] = toupper(nome[0]);
		for(i=0;i<len;i++){
			if(nome[i]==' '){
				nome[i+1]=toupper(nome[i+1]);
			}
		}
		for(i=0;i<len;i++){
			if(nome[i]==' '){
				pesp=i;
				i=len+1;
			}
		}
		for(i=0;i<pesp;i++){
			first[i]=nome[i];
		}
		for(i=0;i<len;i++){
			if(nome[i]==' '){
				uesp=i;
			}
		}
		for(i=uesp,j=0;i<len;i++,j++){
			last[j]=nome[i];
		}
			for(i=pesp,j=0;i<uesp;i++){
			if(nome[i]==' '){
				mid[j] = nome[i];
				mid[j+1]=nome[i+1];
				mid[j+2]='.';
				j=j+3;
			}
		}
		strcpy(nomeconv,first);
		strcat(nomeconv,mid);
		strcat(nomeconv,last);
		strcpy(funcionario[cod-1].nome,nomeconv);
		//printf("\n%s\n",nomeconv);
		system("cls");
		do{
			printf("\nDigite o Sexo do Funcion�rio (m/f): ");
			scanf(" %c",&sexo);
			if(sexo =='m' || sexo=='f'){
				funcionario[cod-1].sexo=sexo;
				sexvalid=1;
				system("cls");
			}
			else{
				system("cls");
			}
		}while(sexvalid==0);
		printf("\nDigite o sal�rio do funcion�rio: ");
		scanf("%f",&sal);
		funcionario[cod-1].salario=sal;
		system("cls");
		printf("Usu�rio Editado com sucesso.\n\nNome: %s\nSexo: %c\nSal�rio: %.2f\n\n",funcionario[cod-1].nome,funcionario[cod-1].sexo,funcionario[cod-1].salario);
		system("pause");
		system("cls");
}
//M�dulo da lista de funcion�rios
void listfunc(){
	int i=0;
	system("cls");
	printf("\t   || Funcion�rios ||\n");
	printf("\n|C�digo | %-25s |Sexo | Sal�rio|\n","Nome");
	for(i=0;i<funcnum;i++){
		printf("|%-7d| %-25s |%-5c| %-7.2f|\n",funcionario[i].cod+1,funcionario[i].nome,funcionario[i].sexo,funcionario[i].salario);
	}
	system("pause");
	system("cls");	
}
