# Sistema de Combate (perspectiva do [Jogador](../classes/PLAYER.md)).

### Como funciona...

Para todas as ações são realizados [Testes](TESTES.md) do Jogador e do [Inimigo](../classes/FOE.md) e os resultados bem sucedidos são comparados para decidir o sucesso da ação.

O momento de combate continua até que um dos dois personagens seja finalizado.

## Ações do Jogador 

> **Nota:** Considere sempre o primeiro Teste dos exemplos de caso sendo do Jogador.

#### Caso escolha `Atacar()`:

* **Caso Ideal:** inimigo defendendo
    * `Teste Ataque > Teste Defesa`:
        > **Sucesso:** Inimigo recebe golpe.</br>
            **1°:** Vida do Inimigo reduz HP em X valor de força do Jogador; </br>
            **2°:** Próximo Turno;
        
        > **Falha**: Inimigo defende golpe.</br>
            **1°:** Perde a vez; </br>
            **2°:** Próximo Turno;
* **Caso não Ideal:** inimigo atacando:
    * `Teste Ataque > Teste Ataque`:
        > **Sucesso:** Inimigo recebe golpe e ataca Jogador. </br>
            **1°:** Vida do Inimigo reduz HP em valor de força do Jogador; </br>
            **2°:** Vida do Jogador reduz HP em **metade(arredondado para cima)** valor de força do Inimigo; </br> 
            **3°:** Próximo Turno;
        
        > **Falha:** Jogador falha e recebe golpe de Inimigo </br>
            **1°:** Vida do Jogador reduz HP em valor de força do Inimigo; </br>
            **2°:** Próximo Turno;

#### Caso escolha `Defender()`:

* **Caso Ideal**: inimigo atacando:
    * `Teste Defesa > Teste Ataque`
        > **Sucesso**: Jogador defende golpe. </br>
            **1°:** Perde a vez; </br>
            **2°:** Próximo Turno;
        
        > **Falha:** Jogador recebe golpe. </br>
            **1°:** Vida do Jogador reduz HP em valor de força do Inimigo; </br>
            **2°:** Próximo Turno;

* **Caso não Ideal**: inimigo defendendo:</br>
    ÚNICO: Não há ataques, próximo turno.

#### Caso escolha `UsarItem()`:

> **Nota:** Usar item não é uma ação principal, apos usar um item o Jogador pode escolher `Atacar()` ou `Defender()`.

* **Caso Ideal:** Escolhe um Item.

    * **1:** Exibe os [Itens](../classes/ITEM.md) armazenados em [Mochila](../classes/BACKPACK.md) e suas quantidades;
    * **2:** Escolhe o item;
    * **3.1 (Consumíveis):** </br> 
        * Aplica [Efeito](/) ao Jogador;
        * Subtrai Item.
    * **3.2: (Equipamentos)** </br>
        * Equipa Item;
        * Aplica Bônus/Ônus ao Jogador;
        * Altera Estado de item.

* **Caso não Ideal:** Cancela ação.
    * Retorna para Menu de ações.
