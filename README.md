# 🎮 CMD_RPG: RPG Text-Based Engine

Este é um projeto de desenvolvimento de um motor (engine) de RPG baseado em texto, com mecânicas estruturadas de combate, progressão de atributos, gerenciamento de inventário e testes de sorte baseados em dados (Dices). Todo o núcleo do software foi projetado e codificado seguindo estritamente as especificações contidas na pasta `docs` do repositório.

---

## 📂 Estrutura do Projeto e Documentação

O desenvolvimento do código é guiado pelos arquivos de especificação contidos na pasta de documentação, os quais mapeiam as entidades e regras de negócio do sistema:

*   **`docs/DICTONARY.md`**: Glossário de termos e termos técnicos utilizados no universo e código do sistema.
*   **Módulos de Entidades (`docs/classes/`):**
    *   `PLAYER.md`: Estrutura do jogador, progressão de nível, HP e tabelas de Força/Defesa.
    *   `FOE.md`: Atributos do inimigo, mecânicas de bônus, drops de experiência (EXP) e Cash.
    *   `ITEM.md`: Definição de propriedades de itens (Preço, Consumíveis, Equipáveis).
    *   `BACKPACK.md`: Sistema de inventário, armazenamento de itens e controle de carteira (Cash).
*   **Módulos de Regras (`docs/logic/`):**
    *   `TESTES.md`: Mecânica de cálculo do Valor Máximo de Teste (`VMT`), rolagens de dados ($d10$/$d6$) e validação de sucesso/falha de ações.
    *   `COMBAT.md`: Fluxo e matriz de combate (Ataque vs Ataque, Ataque vs Defesa) para casos ideais e não ideais.

---

## ⚔️ Funcionalidades Principais

### 1. Sistema Dinâmico de Testes (Dados)
A resolução de ações físicas, ataques e esquivas depende do nível do jogador. O sistema calcula o Valor Máximo de Teste (`VMT`) que dita quais e quantos dados serão rolados (ex: $1d10$ no nível 1, expandindo com $d6$ adicionais em níveis superiores).

### 2. Combate por Turnos e Escalonamento
O combate avalia as ações escolhidas por ambas as entidades simultaneamente.
*   **Casos Ideais:** Sucessos limpos que aplicam o dano total baseado em Atributo + Rolagem.
*   **Casos Não Ideais:** Falhas parciais ou empates táticos que resultam em redução de dano (arredondado para cima) ou perda de turno.

### 3. Progressão de Nível Crítica
O jogador evolui acumulando EXP de inimigos derrotados. A partir do nível 12, os atributos base do jogador deixam de seguir tabelas fixas e passam a escalonar dinamicamente através de fórmulas flutuantes atreladas ao `VMT` corrente:
*   $$\text{Força} = VMT \times 0.25$$
*   $$\text{Defesa} = VMT \times 0.35$$

### 4. Economia e Inventário
Gerenciamento de recursos através da `Mochila`. O jogador pode acumular `Cash` de derrotas inimigas para comprar consumíveis e itens equipáveis que alteram temporariamente ou permanentemente seus estados de batalha.

---

## 📜 Licença

Este projeto está licenciado sob a Licença MIT. Isso significa que você é livre para usar, copiar, modificar e distribuir o código, desde que inclua o aviso de direitos autorais original.

Consulte o arquivo [LICENSE](LICENSE) para obter mais detalhes.
