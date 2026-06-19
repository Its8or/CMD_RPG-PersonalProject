# Jogador

### Possui:

* HP;
* LVL;
* EXP;
* FORÇA ([Base](DICTONARY.md/#ℹ️-base));
* DEFESA ([Base](DICTONARY.md/#ℹ️-base));
* [MOCHILA](BACKPACK.md);
    * CASH;
    * ITENS; (nome, quantidade e descrição);

### Ações:

#### 1. Em combate:

* Atacar();
* Defender();
* Usar_Item();

#### 2. Fora de Combate:

* Ir para Combate (Próxima partida);
* Ir para loja (Comprar Item);

### 3. Lógicas do Jogador.
#### 3.1. Cálculo de Atributos (por nível):


|NÍVEL (rolagem)  |Força(Valor)|Defesa(Valor)|
|---|---|---|
|1° ($1d10$)|4|2|
|4° ($1d10+1d6$)|6|4|
|8° ($1d10+2d6$)|7|7|
|+12° ($1d10+3d6$)|$VMT * 0,25$|$VMT * 0,35$ |

>Abreviações:</br>
>    `VMT`: Valor Máximo de Teste