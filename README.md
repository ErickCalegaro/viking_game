# Viking Game
Jogo de plataforma em 2d com a tematica viking, usando liguagem C e biblioteca SDL
.

## 🚀 Começando
Essas instruções permitirão que você obtenha uma cópia do projeto em operação na sua máquina local para fins de desenvolvimento e teste.

Consulte **[Releases](##-📦-Releases)** para saber como instalar o jogo.

### 📋 Pré-requisitos
O que você precisa para instalar o repositório para desenvolvimento.

#### 🖥 Hardware
* RAM Minima: 4GB
* CPU Minima: Dual-Core
* FS  Minimo: 200MB

#### 📲 Software
* SO  Minima: Windows 10 (Ou tente outro por sua conta e risco)

#### 🗿 Skills
* Desenvolvimento avançado em linguagem C
* Conhecimento da biblioteca SDL2

### 🔧 Instalando
Passo a passo para realizar uma copia de desenvolvimento operando na sua maquina:
* Partindo da prerrogativa que sua maquina e seu usuário já estejam configurados

#### 📚 Ferramentas
Precisaremos instalar os seguintes pacotes para o desenvolvimento:
* VS Code: https://code.visualstudio.com/docs/?dv=win64user
* Git Bash: https://github.com/git-for-windows/git/releases/download/v2.44.0.windows.1/Git-2.44.0-64-bit.exe
* mingw: https://www.mingw-w64.org/downloads/#w64devkit (GCC e make)


Após a instalação, execute o comando abaixo para garantir que seu ambiente está OK:
* `git version`
* `gcc -v`

#### 🔗 Obtendo um clone
* Abra o CMD
* Acesse uma pasta de sua preferencia, recomendo que use uma proxima da `C:/`, no caso estou usando a `C:/Projetos`.
* Nela, realize o clone do repositório com o comando ```git clone https://github.com/ErickCalegaro/viking_game.git```

#### 🧱 Compilando
* Ainda com o CMD aberto execute o comando `code .` para abrir o VS Code.
* Execute o atalho Ctrl + Shift + B para compilar o codigo de forma limpa
Caso tenha algum problema, entre em **[Contato](https://api.whatsapp.com/send?phone=5511955828684&text=Ol%C3%A1%2C%20estou%20com%20duvidas%20sobre%20o%20projeto%20Viking%20Game%2C%20pode%20me%20auxiliar%3F)**

## 🧨 Executando
Após o build será criada a pasta output, nela, basta executar o arquivo `VikingGame_V.V.VV.exe`

## 🐞 Depurando
Para definir o nivel de log que deseja utilizar basta alterar o define "LOG_LEVEL" no config.mk. 
Os niveis disponiveis são os seguintes, sendo que números maiores contém também os logs dos menores.

0. LOG_NONE - Não retornará nenhum log
1. LOG_FATAL - Usado para erros que encerrem a execução da aplicação.
2. LOG_ERROR - Usado para casos de erro de interpretação, porém recuperaveis.
3. LOG_WARN - Usado para informações sobre memória e desempenho
4. LOG_INFO - Usado para logs de conexão, input e output
5. LOG_DEBUG - Usado para exibir todas as linhas de log na aplicação (parser, maker, etc...)

* X = Presente no nivel da coluna

| NIVEL | LOG_DEBUG | LOG_INFO  | LOG_WARN  | LOG_ERROR | LOG_FATAL | LOG_NONE  |
| ----- | --------- | --------- | --------- | --------- | --------- | --------- |
| NONE  |           |           |           |           |           |           |
| DEBUG |     X     |           |           |           |           |           |
| INFO  |     X     |     X     |           |           |           |           |
| WARN  |     X     |     X     |     X     |           |           |           |
| ERROR |     X     |     X     |     X     |     X     |           |           |
| FATAL |     X     |     X     |     X     |     X     |     X     |           |


## 📦 Releases
Agora iremos abordar como você pode executar uma release oficial deste projeto.

### 📑 Requisitos

#### 🖥 Hardware
* RAM Minima: 1GB
* CPU Minima: Single-Core
* FS  Minimo: 20MB

#### 📲 Software
* SO  Minima: Windows 7

#### 🗿 Skills
* Nenhuma a ser detalhada aqui

## 🛠️ Construído com
* [GCC](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html) - Linguagem C
* [SDL2](https://wiki.libsdl.org/SDL2/FrontPage) - Biblioteca Gráfica SDL2

## 💬 FAQ

#### Como desabilitar resultados dos headers da SDL2 no Ctrl + Shift + F:
* Acessar File ➡️ Preferences ➡️ Settings ➡️ User/Workspace Settings
* Buscar por `search.exclude`
* Adicionar a pasta `**\SDL2`

RFU

## 📌 Versão
Nós usamos [SemVer](http://semver.org/) para controle de versão. Para as versões disponíveis, observe as **[tags neste repositório](https://github.com/ErickCalegaro/viking_game/tags)**. 

## ✒️ Autores

* **[Erick Calegaro](linkedin.com/in/erick-calegaro/)** - *Arquitetura e implementação inicial*

!TODO: Adicionar créditos dos assets

## 🎁 Expressões de gratidão
* Conte a outras pessoas sobre este projeto 📢;
* Convide o desenvolvedor para tomar uma IPA 🍺;

## 📞 Contato
* Qualquer duvida ou sugestão, pode entrar em contato pelo WhatsApp **[(11) 95582-8684](https://api.whatsapp.com/send?phone=5511955828684&text=Ol%C3%A1%2C%20estou%20com%20duvidas%20sobre%20o%20projeto%20Viking%20Game%2C%20pode%20me%20auxiliar%3F)**
