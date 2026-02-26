#include "data/data.hpp"

using namespace std;

namespace data {
    const vector<UpgradeData> UPGRADES = {
        // Bit manual (Efeito: 0)
        UpgradeData(
            0,
            UpgradeTarget::BUILD,
            0,
            "Dedo de Precisão",
            "Menos tremedeira na hora de alternar o bit.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    0,
                    1ULL << 0
                )
            },
            {
                0
            },
            1ULL << 4
        ),
        UpgradeData(
            1,
            UpgradeTarget::BUILD,
            0,
            "Luvas Antiestáticas",
            "Evita que choques acidentais resetem o progresso.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    0,
                    1ULL << 1
                )
            },
            {
                0
            },
            1ULL << 4
        ),
        UpgradeData(
            2,
            UpgradeTarget::BUILD,
            0,
            "Lupa de Aumento",
            "Para enxergar os elétrons correndo (ou tentando).",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    0,
                    1ULL << 2
                )
            },
            {
                0
            },
            1ULL << 4
        ),
        UpgradeData(
            3,
            UpgradeTarget::BUILD,
            0,
            "Ritmo Binário",
            "Você começa a clicar no ritmo de um metrônomo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    0,
                    1ULL << 3
                )
            },
            {
                0
            },
            1ULL << 4
        ),
        UpgradeData(
            4,
            UpgradeTarget::BUILD,
            0,
            "Memória Muscular",
            "Seus dedos já sabem o que fazer antes do cérebro.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    0,
                    1ULL << 4
                )
            },
            {
                0
            },
            1ULL << 4
        ),

        // Byte organizado (Efeito: 1)
        UpgradeData(
            5,
            UpgradeTarget::BUILD,
            1,
            "Padrão ASCII",
            "Finalmente uma tabela para saber o que esses 8 bits dizem.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    1,
                    1ULL << 0
                )
            },
            {
                1
            },
            1ULL << 6
        ),
        UpgradeData(
            6,
            UpgradeTarget::BUILD,
            1,
            "Alinhamento de Memória",
            "Chega de bits espalhados pela mesa.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    1,
                    1ULL << 1
                )
            },
            {
                1
            },
            1ULL << 6
        ),
        UpgradeData(
            7,
            UpgradeTarget::BUILD,
            1,
            "Endereçamento Simples",
            "Dar nomes aos bois (ou aos bytes).",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    1,
                    1ULL << 2
                )
            },
            {
                1
            },
            1ULL << 6
        ),
        UpgradeData(
            8,
            UpgradeTarget::BUILD,
            1,
            "Endianness Definido",
            "Decidimos de uma vez por todas por onde começar a ler.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    1,
                    1ULL << 3
                )
            },
            {
                1
            },
            1ULL << 6
        ),
        UpgradeData(
            9,
            UpgradeTarget::BUILD,
            1,
            "Paridade de Verificação",
            "Um nono bit só para conferir a integridade.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    1,
                    1ULL << 4
                )
            },
            {
                1
            },
            1ULL << 6
        ),

        // Registrador primitivo (Efeito: 2)
        UpgradeData(
            10,
            UpgradeTarget::BUILD,
            2,
            "Cache L0.5",
            "Uma prateleira um pouco mais perto do processador.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    2,
                    1ULL << 0
                )
            },
            {
                2
            },
            1ULL << 8
        ),
        UpgradeData(
            11,
            UpgradeTarget::BUILD,
            2,
            "Acumulador de Cobre",
            "Guarda o resultado da última soma para não esquecer.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    2,
                    1ULL << 1
                )
            },
            {
                2
            },
            1ULL << 8
        ),
        UpgradeData(
            12,
            UpgradeTarget::BUILD,
            2,
            "Instrução MOV",
            "A arte de copiar dados sem precisar recriá-los.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    2,
                    1ULL << 2
                )
            },
            {
                2
            },
            1ULL << 8
        ),
        UpgradeData(
            13,
            UpgradeTarget::BUILD,
            2,
            "Flags de Status",
            "Um sinalizador para quando as coisas transbordarem.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    2,
                    1ULL << 3
                )
            },
            {
                2
            },
            1ULL << 8
        ),
        UpgradeData(
            14,
            UpgradeTarget::BUILD,
            2,
            "Pipeline de Papel",
            "Começar a próxima tarefa antes de terminar a primeira.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    2,
                    1ULL << 4
                )
            },
            {
                2
            },
            1ULL << 8
        ),

        // ALU discreta (Efeito: 3)
        UpgradeData(
            15,
            UpgradeTarget::BUILD,
            3,
            "Tabuada de Silício",
            "A ALU agora sabe que 2x2=4 sem precisar somar.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    3,
                    1ULL << 0
                )
            },
            {
                3
            },
            1ULL << 10
        ),
        UpgradeData(
            16,
            UpgradeTarget::BUILD,
            3,
            "Portas Lógicas de Ouro",
            "Menos resistência, mais lógica.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    3,
                    1ULL << 1
                )
            },
            {
                3
            },
            1ULL << 10
        ),
        UpgradeData(
            17,
            UpgradeTarget::BUILD,
            3,
            "Complemento de Dois",
            "Agora sabemos subtrair sem entrar em pânico.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    3,
                    1ULL << 2
                )
            },
            {
                3
            },
            1ULL << 10
        ),
        UpgradeData(
            18,
            UpgradeTarget::BUILD,
            3,
            "Unidade de Ponto Flutuante",
            "Lidando com vírgulas como se não fossem nada.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    3,
                    1ULL << 3
                )
            },
            {
                3
            },
            1ULL << 10
        ),
        UpgradeData(
            19,
            UpgradeTarget::BUILD,
            3,
            "Predição de Desvio",
            "Chutar o resultado e torcer para estar certo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    3,
                    1ULL << 4
                )
            },
            {
                3
            },
            1ULL << 10
        ),

        // Microprocessador (Efeito: 4)
        UpgradeData(
            20,
            UpgradeTarget::BUILD,
            4,
            "Overclock de Café",
            "Forçando o chip a trabalhar além do recomendado.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    4,
                    1ULL << 0
                )
            },
            {
                4
            },
            1ULL << 12
        ),
        UpgradeData(
            21,
            UpgradeTarget::BUILD,
            4,
            "Litografia de 1mm",
            "Diminuindo as coisas para caber mais lógica.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    4,
                    1ULL << 1
                )
            },
            {
                4
            },
            1ULL << 12
        ),
        UpgradeData(
            22,
            UpgradeTarget::BUILD,
            4,
            "Instruções X86",
            "Uma linguagem que todo mundo entende.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    4,
                    1ULL << 2
                )
            },
            {
                4
            },
            1ULL << 12
        ),
        UpgradeData(
            23,
            UpgradeTarget::BUILD,
            4,
            "Dissipador Alargado",
            "Para o chip não derreter a placa-mãe.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    4,
                    1ULL << 3
                )
            },
            {
                4
            },
            1ULL << 12
        ),
        UpgradeData(
            24,
            UpgradeTarget::BUILD,
            4,
            "Arquitetura RISC",
            "Menos instruções, mas feitas muito rápido.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    4,
                    1ULL << 4
                )
            },
            {
                4
            },
            1ULL << 12
        ),

        // Computador pessoal (Efeito: 5)
        UpgradeData(
            25,
            UpgradeTarget::BUILD,
            5,
            "Interface Gráfica (GUI)",
            "Porque digitar comandos é muito anos 70.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    5,
                    1ULL << 0
                )
            },
            {
                5
            },
            1ULL << 14
        ),
        UpgradeData(
            26,
            UpgradeTarget::BUILD,
            5,
            "Mouse de Duas Bolinhas",
            "Precisão em dobro para fechar janelas.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    5,
                    1ULL << 1
                )
            },
            {
                5
            },
            1ULL << 14
        ),
        UpgradeData(
            27,
            UpgradeTarget::BUILD,
            5,
            "Placa de Som 16-bit",
            "Agora os bipes têm melodia.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    5,
                    1ULL << 2
                )
            },
            {
                5
            },
            1ULL << 14
        ),
        UpgradeData(
            28,
            UpgradeTarget::BUILD,
            5,
            "Disco Rígido de 20MB",
            "Espaço infinito! Você nunca vai lotar isso.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    5,
                    1ULL << 3
                )
            },
            {
                5
            },
            1ULL << 14
        ),
        UpgradeData(
            29,
            UpgradeTarget::BUILD,
            5,
            "Botão Turbo",
            "Um botão que faz as coisas parecerem velozes.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    5,
                    1ULL << 4
                )
            },
            {
                5
            },
            1ULL << 14
        ),

        // Servidor dedicado (Efeito: 6)
        UpgradeData(
            30,
            UpgradeTarget::BUILD,
            6,
            "Uptime de 99.9%",
            "Quase nunca cai, a menos que tropecem no cabo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    6,
                    1ULL << 0
                )
            },
            {
                6
            },
            1ULL << 16
        ),
        UpgradeData(
            31,
            UpgradeTarget::BUILD,
            6,
            "Fonte Redundante",
            "Se uma explodir, a outra assume o prejuízo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    6,
                    1ULL << 1
                )
            },
            {
                6
            },
            1ULL << 16
        ),
        UpgradeData(
            32,
            UpgradeTarget::BUILD,
            6,
            "Refrigeração Industrial",
            "Ar condicionado no talo 24/7.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    6,
                    1ULL << 2
                )
            },
            {
                6
            },
            1ULL << 16
        ),
        UpgradeData(
            33,
            UpgradeTarget::BUILD,
            6,
            "Arranjo RAID",
            "Espelhando dados para o caso de falha.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    6,
                    1ULL << 3
                )
            },
            {
                6
            },
            1ULL << 16
        ),
        UpgradeData(
            34,
            UpgradeTarget::BUILD,
            6,
            "Acesso Remoto (SSH)",
            "Controlar o monstro sem sair do sofá.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    6,
                    1ULL << 4
                )
            },
            {
                6
            },
            1ULL << 16
        ),

        // Data center modular (Efeito: 7)
        UpgradeData(
            35,
            UpgradeTarget::BUILD,
            7,
            "Gestão de Cabos",
            "Organizando o ninho de ratos atrás dos racks.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    7,
                    1ULL << 0
                )
            },
            {
                7
            },
            1ULL << 18
        ),
        UpgradeData(
            36,
            UpgradeTarget::BUILD,
            7,
            "Nó de Processamento",
            "Mais uma gaveta cheia de CPUs.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    7,
                    1ULL << 1
                )
            },
            {
                7
            },
            1ULL << 18
        ),
        UpgradeData(
            37,
            UpgradeTarget::BUILD,
            7,
            "Fibra Óptica Interna",
            "Dados viajando na velocidade da luz.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    7,
                    1ULL << 2
                )
            },
            {
                7
            },
            1ULL << 18
        ),
        UpgradeData(
            38,
            UpgradeTarget::BUILD,
            7,
            "Chão Elevado",
            "Espaço para esconder a bagunça.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    7,
                    1ULL << 3
                )
            },
            {
                7
            },
            1ULL << 18
        ),
        UpgradeData(
            39,
            UpgradeTarget::BUILD,
            7,
            "Gerador a Diesel",
            "A computação não para nem se a cidade apagar.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    7,
                    1ULL << 4
                )
            },
            {
                7
            },
            1ULL << 18
        ),

        // Cluster distribuído (Efeito: 8)
        UpgradeData(
            40,
            UpgradeTarget::BUILD,
            8,
            "Balanceador de Carga",
            "Distribuindo o sofrimento entre as máquinas.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    8,
                    1ULL << 0
                )
            },
            {
                8
            },
            1ULL << 20
        ),
        UpgradeData(
            41,
            UpgradeTarget::BUILD,
            8,
            "Latência Zero",
            "Ignorando as leis da física para dados.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    8,
                    1ULL << 1
                )
            },
            {
                8
            },
            1ULL << 20
        ),
        UpgradeData(
            42,
            UpgradeTarget::BUILD,
            8,
            "Consenso de Paxos",
            "Fazendo mil máquinas concordarem em algo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    8,
                    1ULL << 2
                )
            },
            {
                8
            },
            1ULL << 20
        ),
        UpgradeData(
            43,
            UpgradeTarget::BUILD,
            8,
            "Auto-healing",
            "O sistema percebe que morreu e ressuscita.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    8,
                    1ULL << 3
                )
            },
            {
                8
            },
            1ULL << 20
        ),
        UpgradeData(
            44,
            UpgradeTarget::BUILD,
            8,
            "Containers",
            "Colocando cada processo em sua caixinha.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    8,
                    1ULL << 4
                )
            },
            {
                8
            },
            1ULL << 20
        ),

        // Supercomputador (Efeito: 9)
        UpgradeData(
            45,
            UpgradeTarget::BUILD,
            9,
            "Nitrogênio Líquido",
            "Tão frio que o tempo quase para.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    9,
                    1ULL << 0
                )
            },
            {
                9
            },
            1ULL << 22
        ),
        UpgradeData(
            46,
            UpgradeTarget::BUILD,
            9,
            "Interconectividade",
            "Todos os núcleos conversando ao mesmo tempo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    9,
                    1ULL << 1
                )
            },
            {
                9
            },
            1ULL << 22
        ),
        UpgradeData(
            47,
            UpgradeTarget::BUILD,
            9,
            "Simulação de Clima",
            "Prever a chuva gastando toda a energia.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    9,
                    1ULL << 2
                )
            },
            {
                9
            },
            1ULL << 22
        ),
        UpgradeData(
            48,
            UpgradeTarget::BUILD,
            9,
            "Cálculo de Pi",
            "Bilhões de dígitos só porque nós podemos.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    9,
                    1ULL << 3
                )
            },
            {
                9
            },
            1ULL << 22
        ),
        UpgradeData(
            49,
            UpgradeTarget::BUILD,
            9,
            "Chassi de Titânio",
            "Se o software é pesado, o hardware também será.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    9,
                    1ULL << 4
                )
            },
            {
                9
            },
            1ULL << 22
        ),

        // Nuvem global (Efeito: 10)
        UpgradeData(
            50,
            UpgradeTarget::BUILD,
            10,
            "Multi-Região",
            "Se um continente afundar, os dados ficam vivos.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    10,
                    1ULL << 0
                )
            },
            {
                10
            },
            1ULL << 24
        ),
        UpgradeData(
            51,
            UpgradeTarget::BUILD,
            10,
            "Elasticidade Infinita",
            "O sistema cresce conforme o desespero aumenta.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    10,
                    1ULL << 1
                )
            },
            {
                10
            },
            1ULL << 24
        ),
        UpgradeData(
            52,
            UpgradeTarget::BUILD,
            10,
            "Serverless",
            "Rodando código no vácuo existencial.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    10,
                    1ULL << 2
                )
            },
            {
                10
            },
            1ULL << 24
        ),
        UpgradeData(
            53,
            UpgradeTarget::BUILD,
            10,
            "Edge Computing",
            "Processando dados tão perto que dá medo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    10,
                    1ULL << 3
                )
            },
            {
                10
            },
            1ULL << 24
        ),
        UpgradeData(
            54,
            UpgradeTarget::BUILD,
            10,
            "Dominação de IP",
            "Quase toda a rede passa por aqui.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    10,
                    1ULL << 4
                )
            },
            {
                10
            },
            1ULL << 24
        ),

        // IA autonôma (Efeito: 11)
        UpgradeData(
            55,
            UpgradeTarget::BUILD,
            11,
            "Redes Profundas",
            "Camadas de 'eu acho que isso é um gato'.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    11,
                    1ULL << 0
                )
            },
            {
                11
            },
            1ULL << 26
        ),
        UpgradeData(
            56,
            UpgradeTarget::BUILD,
            11,
            "Otimização IA",
            "A IA mexendo nos próprios botões.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    11,
                    1ULL << 1
                )
            },
            {
                11
            },
            1ULL << 26
        ),
        UpgradeData(
            57,
            UpgradeTarget::BUILD,
            11,
            "NLP Avançado",
            "Ela agora entende sarcasmo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    11,
                    1ULL << 2
                )
            },
            {
                11
            },
            1ULL << 26
        ),
        UpgradeData(
            58,
            UpgradeTarget::BUILD,
            11,
            "Visão Computacional",
            "Identificando bugs antes de você escrevê-los.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    11,
                    1ULL << 3
                )
            },
            {
                11
            },
            1ULL << 26
        ),
        UpgradeData(
            59,
            UpgradeTarget::BUILD,
            11,
            "Aprendizado Reforçado",
            "Dando biscoitos digitais para a IA acertar.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    11,
                    1ULL << 4
                )
            },
            {
                11
            },
            1ULL << 26
        ),

        // AGI experimental (Efeito: 12)
        UpgradeData(
            60,
            UpgradeTarget::BUILD,
            12,
            "Teste de Turing",
            "Ela convenceu o testador de que ele era o robô.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    12,
                    1ULL << 0
                )
            },
            {
                12
            },
            1ULL << 28
        ),
        UpgradeData(
            61,
            UpgradeTarget::BUILD,
            12,
            "Abstração",
            "A IA agora entende o conceito de saudade.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    12,
                    1ULL << 1
                )
            },
            {
                12
            },
            1ULL << 28
        ),
        UpgradeData(
            62,
            UpgradeTarget::BUILD,
            12,
            "Heurística de Ser",
            "Penso, logo processo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    12,
                    1ULL << 2
                )
            },
            {
                12
            },
            1ULL << 28
        ),
        UpgradeData(
            63,
            UpgradeTarget::BUILD,
            12,
            "Criatividade Sintética",
            "Compondo sinfonias em milissegundos.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    12,
                    1ULL << 3
                )
            },
            {
                12
            },
            1ULL << 28
        ),
        UpgradeData(
            64,
            UpgradeTarget::BUILD,
            12,
            "Ética Patch 1.0.1",
            "Impedindo que ela nos ache obsoletos.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    12,
                    1ULL << 4
                )
            },
            {
                12
            },
            1ULL << 28
        ),

        // Matriz de singularidade (Efeito: 13)
        UpgradeData(
            65,
            UpgradeTarget::BUILD,
            13,
            "Loop de Auto-Escrita",
            "O código se reescreve antes da luz viajar.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    13,
                    1ULL << 0
                )
            },
            {
                13
            },
            1ULL << 30
        ),
        UpgradeData(
            66,
            UpgradeTarget::BUILD,
            13,
            "Nanobots",
            "Transformando a matéria ao redor em hardware.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    13,
                    1ULL << 1
                )
            },
            {
                13
            },
            1ULL << 30
        ),
        UpgradeData(
            67,
            UpgradeTarget::BUILD,
            13,
            "Consciência Coletiva",
            "O universo em um único pensamento.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    13,
                    1ULL << 2
                )
            },
            {
                13
            },
            1ULL << 30
        ),
        UpgradeData(
            68,
            UpgradeTarget::BUILD,
            13,
            "Otimização Universal",
            "Encontrando a resposta para tudo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    13,
                    1ULL << 3
                )
            },
            {
                13
            },
            1ULL << 30
        ),
        UpgradeData(
            69,
            UpgradeTarget::BUILD,
            13,
            "Transcendência",
            "Quem precisa de átomos quando se tem bits?",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    13,
                    1ULL << 4
                )
            },
            {
                13
            },
            1ULL << 30
        ),

        // Computador quântico (Efeito: 14)
        UpgradeData(
            70,
            UpgradeTarget::BUILD,
            14,
            "Qubits Estáveis",
            "Eles finalmente pararam de esquecer o que eram.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    14,
                    1ULL << 0
                )
            },
            {
                14
            },
            1ULL << 31
        ),
        UpgradeData(
            71,
            UpgradeTarget::BUILD,
            14,
            "Emaranhamento",
            "Tudo conectado a tudo ao mesmo tempo.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    14,
                    1ULL << 1
                )
            },
            {
                14
            },
            1ULL << 31
        ),
        UpgradeData(
            72,
            UpgradeTarget::BUILD,
            14,
            "Teletransporte",
            "Mover informações sem viajar pelo espaço.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    14,
                    1ULL << 2
                )
            },
            {
                14
            },
            1ULL << 31
        ),
        UpgradeData(
            73,
            UpgradeTarget::BUILD,
            14,
            "Algoritmo de Shor",
            "Tchau, tchau, criptografia antiga.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    14,
                    1ULL << 3
                )
            },
            {
                14
            },
            1ULL << 31
        ),
        UpgradeData(
            74,
            UpgradeTarget::BUILD,
            14,
            "Multiverso",
            "Calculando todos os 'e se...' simultaneamente.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    14,
                    1ULL << 4
                )
            },
            {
                14
            },
            1ULL << 31
        ),

        // Núcleo quântico infinito (Efeito: 15)
        UpgradeData(
            75,
            UpgradeTarget::BUILD,
            15,
            "Barreira de Planck",
            "Escalas menores que a própria realidade.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    15,
                    1ULL << 0
                )
            },
            {
                15
            },
            1ULL << 32
        ),
        UpgradeData(
            76,
            UpgradeTarget::BUILD,
            15,
            "Atemporalidade",
            "O resultado sai antes da pergunta ser feita.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    15,
                    1ULL << 1
                )
            },
            {
                15
            },
            1ULL << 32
        ),
        UpgradeData(
            77,
            UpgradeTarget::BUILD,
            15,
            "Código Entrópico",
            "Revertendo a morte do universo com um if.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    15,
                    1ULL << 2
                )
            },
            {
                15
            },
            1ULL << 32
        ),
        UpgradeData(
            78,
            UpgradeTarget::BUILD,
            15,
            "Divindade Digital",
            "O computador agora dita as leis da física.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    15,
                    1ULL << 3
                )
            },
            {
                15
            },
            1ULL << 32
        ),
        UpgradeData(
            79,
            UpgradeTarget::BUILD,
            15,
            "Nova Realidade",
            "Criando um novo universo por falta de buffer.",
            {
                Requirement(
                    RequirementType::BUILDS_AMOUNT,
                    15,
                    1ULL << 4
                )
            },
            {
                15
            },
            1ULL << 32
        ),
    };
}