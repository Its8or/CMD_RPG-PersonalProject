# Sistema de Testes

### Como funciona...

Antes dos testes do Jogador serem comparados ao do Inimigo eles passam por testes individuais para validar se é possível realizar a ação.

Ao evoluir o nível do seu personagem a chance de ter sucesso em `Atacar()` ou `Defender()` mudam.

Para todas as menções posteriores: `Rolagem` será uma referência direta a Teste e `Dados` será uma referência ao valor máximo de um teste.

### As Rolagens.

Todas as rolagens são baseadas em um dado de dez lados ($d10$). A cada 4 níveis é adicionado um dado de seis lados($d6$) às rolagens. Assim, o valor máximo de um teste no primeiro nível é `10`, no quarto nível é `16`, no oitávo `22`, e assim por diante...

#### Exemplo: Rolagem para  `Atacar()`

**Gera número aleatório dentro de uma série de 1 à `Valor Máximo do dado`**

> **Sucesso:** `número aleatório >= valor de força` </br>
> Retorna número para próxima etapa em [Caso de escolha: Atacar](../logic/COMBAT.md/#caso-escolha-atacar) onde vai ser realizado a comparação entre resultados das rolagens de Jogador e Inimigo.

> **Falha:** `número aleatório < valor de força` </br>
> Retorna 0, o Jogador entra automaticamente na rota de falha, do caso exemplificado, [Caso de escolha: Atacar](../logic/COMBAT.md/#caso-escolha-atacar).