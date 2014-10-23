SyncPass
========

SyncPass é uma DLL Para fazer o hook da troca da senha dos usuários do Windows, e ou do Active Directory. Link referente a api http://msdn.microsoft.com/en-us/library/windows/desktop/ms721882(v=vs.85).aspx

Após criar a .dll deve-se copiar a mesma para o diretório **c:\windows\system32\** indiferente da plataforma 32 ou 64.

As alterações da senha ficaram salvas em **c:\tmp\debug.log**

Lembre-se de ativar a informação no registro em.

```
Windows Registry Editor Version 5.00
[HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Lsa]
"Notification Packages"="SyncPass.dll"
```

Atenção:
Este projeto foi compilado utilizando o Dev-C++ 5.7 x64, porém no momento que for compilar, ele retora o erro descrito no link dos desenvolvedores http://sourceforge.net/p/orwelldevcpp/tickets/136/?limit=25 

Para resolver +- na linha 27 deve-se alterar de
```$(CC) -shared $(LINKOBJ) -o $(BIN) $(LIBS) -Wl,--output-def,$(DEFFILE),--out-implib,$(STATICLIB),--add-stdcall-alias``` 
para
```$(CC) -shared $(LINKOBJ) -o $(BIN) $(LIBS) -Wl,--output-def,$(DEF),--out-implib,$(STATIC),--add-stdcall-alias```

```
Testado:
2012 R2 x64 - ok
2008 R2 x64 - OK
2003 x32 -  
2003 x64 - 
```
