#include <upgrades_data.hpp>

using namespace std;

const vector<UpgradeData> UPGRADES = {
    // Bit manual (Efeito: 0)
    UpgradeData(
        0,
        "Dedo de Precisão",
        "Menos tremedeira na hora de alternar o bit.",
        {
            0
        },
        1ULL << 4
    ),
    UpgradeData(
        1,
        "Luvas Antiestáticas",
        "Evita que choques acidentais resetem o progresso.",
        {
            0
        },
        1ULL << 4
    ),
    UpgradeData(
        2,
        "Lupa de Aumento",
        "Para enxergar os elétrons correndo (ou tentando).",
        {
            0
        },
        1ULL << 4
    ),
    UpgradeData(
        3,
        "Ritmo Binário",
        "Você começa a clicar no ritmo de um metrônomo.",
        {
            0
        },
        1ULL << 4
    ),
    UpgradeData(
        4,
        "Memória Muscular",
        "Seus dedos já sabem o que fazer antes do cérebro.",
        {
            0
        },
        1ULL << 4
    ),

    // Byte organizado (Efeito: 1)
    UpgradeData(
        5,
        "Padrão ASCII",
        "Finalmente uma tabela para saber o que esses 8 bits dizem.",
        {
            1
        },
        1ULL << 6
    ),
    UpgradeData(
        6,
        "Alinhamento de Memória",
        "Chega de bits espalhados pela mesa.",
        {
            1
        },
        1ULL << 6
    ),
    UpgradeData(
        7,
        "Endereçamento Simples",
        "Dar nomes aos bois (ou aos bytes).",
        {
            1
        },
        1ULL << 6
    ),
    UpgradeData(
        8,
        "Endianness Definido",
        "Decidimos de uma vez por todas por onde começar a ler.",
        {
            1
        },
        1ULL << 6
    ),
    UpgradeData(
        9,
        "Paridade de Verificação",
        "Um nono bit só para conferir a integridade.",
        {
            1
        },
        1ULL << 6
    ),

    // Registrador primitivo (Efeito: 2)
    UpgradeData(
        10,
        "Cache L0.5",
        "Uma prateleira um pouco mais perto do processador.",
        {
            2
        },
        1ULL << 8
    ),
    UpgradeData(
        11,
        "Acumulador de Cobre",
        "Guarda o resultado da última soma para não esquecer.",
        {
            2
        },
        1ULL << 8
    ),
    UpgradeData(
        12,
        "Instrução MOV",
        "A arte de copiar dados sem precisar recriá-los.",
        {
            2
        },
        1ULL << 8
    ),
    UpgradeData(
        13,
        "Flags de Status",
        "Um sinalizador para quando as coisas transbordarem.",
        {
            2
        },
        1ULL << 8
    ),
    UpgradeData(
        14,
        "Pipeline de Papel",
        "Começar a próxima tarefa antes de terminar a primeira.",
        {
            2
        },
        1ULL << 8
    ),

    // ALU discreta (Efeito: 3)
    UpgradeData(
        15,
        "Tabuada de Silício",
        "A ALU agora sabe que 2x2=4 sem precisar somar.",
        {
            3
        },
        1ULL << 10
    ),
    UpgradeData(
        16,
        "Portas Lógicas de Ouro",
        "Menos resistência, mais lógica.",
        {
            3
        },
        1ULL << 10
    ),
    UpgradeData(
        17,
        "Complemento de Dois",
        "Agora sabemos subtrair sem entrar em pânico.",
        {
            3
        },
        1ULL << 10
    ),
    UpgradeData(
        18,
        "Unidade de Ponto Flutuante",
        "Lidando com vírgulas como se não fossem nada.",
        {
            3
        },
        1ULL << 10
    ),
    UpgradeData(
        19,
        "Predição de Desvio",
        "Chutar o resultado e torcer para estar certo.",
        {
            3
        },
        1ULL << 10
    ),

    // Microprocessador (Efeito: 4)
    UpgradeData(
        20,
        "Overclock de Café",
        "Forçando o chip a trabalhar além do recomendado.",
        {
            4
        },
        1ULL << 12
    ),
    UpgradeData(
        21,
        "Litografia de 1mm",
        "Diminuindo as coisas para caber mais lógica.",
        {
            4
        },
        1ULL << 12
    ),
    UpgradeData(
        22,
        "Instruções X86",
        "Uma linguagem que todo mundo entende.",
        {
            4
        },
        1ULL << 12
    ),
    UpgradeData(
        23,
        "Dissipador Alargado",
        "Para o chip não derreter a placa-mãe.",
        {
            4
        },
        1ULL << 12
    ),
    UpgradeData(
        24,
        "Arquitetura RISC",
        "Menos instruções, mas feitas muito rápido.",
        {
            4
        },
        1ULL << 12
    ),

    // Computador pessoal (Efeito: 5)
    UpgradeData(
        25,
        "Interface Gráfica (GUI)",
        "Porque digitar comandos é muito anos 70.",
        {
            5
        },
        1ULL << 14
    ),
    UpgradeData(
        26,
        "Mouse de Duas Bolinhas",
        "Precisão em dobro para fechar janelas.",
        {
            5
        },
        1ULL << 14
    ),
    UpgradeData(
        27,
        "Placa de Som 16-bit",
        "Agora os bipes têm melodia.",
        {
            5
        },
        1ULL << 14
    ),
    UpgradeData(
        28,
        "Disco Rígido de 20MB",
        "Espaço infinito! Você nunca vai lotar isso.",
        {
            5
        },
        1ULL << 14
    ),
    UpgradeData(
        29,
        "Botão Turbo",
        "Um botão que faz as coisas parecerem velozes.",
        {
            5
        },
        1ULL << 14
    ),

    // Servidor dedicado (Efeito: 6)
    UpgradeData(
        30,
        "Uptime de 99.9%",
        "Quase nunca cai, a menos que tropecem no cabo.",
        {
            6
        },
        1ULL << 16
    ),
    UpgradeData(
        31,
        "Fonte Redundante",
        "Se uma explodir, a outra assume o prejuízo.",
        {
            6
        },
        1ULL << 16
    ),
    UpgradeData(
        32,
        "Refrigeração Industrial",
        "Ar condicionado no talo 24/7.",
        {
            6
        },
        1ULL << 16
    ),
    UpgradeData(
        33,
        "Arranjo RAID",
        "Espelhando dados para o caso de falha.",
        {
            6
        },
        1ULL << 16
    ),
    UpgradeData(
        34,
        "Acesso Remoto (SSH)",
        "Controlar o monstro sem sair do sofá.",
        {
            6
        },
        1ULL << 16
    ),

    // Data center modular (Efeito: 7)
    UpgradeData(
        35,
        "Gestão de Cabos",
        "Organizando o ninho de ratos atrás dos racks.",
        {
            7
        },
        1ULL << 18
    ),
    UpgradeData(
        36,
        "Nó de Processamento",
        "Mais uma gaveta cheia de CPUs.",
        {
            7
        },
        1ULL << 18
    ),
    UpgradeData(
        37,
        "Fibra Óptica Interna",
        "Dados viajando na velocidade da luz.",
        {
            7
        },
        1ULL << 18
    ),
    UpgradeData(
        38,
        "Chão Elevado",
        "Espaço para esconder a bagunça.",
        {
            7
        },
        1ULL << 18
    ),
    UpgradeData(
        39,
        "Gerador a Diesel",
        "A computação não para nem se a cidade apagar.",
        {
            7
        },
        1ULL << 18
    ),

    // Cluster distribuído (Efeito: 8)
    UpgradeData(
        40,
        "Balanceador de Carga",
        "Distribuindo o sofrimento entre as máquinas.",
        {
            8
        },
        1ULL << 20
    ),
    UpgradeData(
        41,
        "Latência Zero",
        "Ignorando as leis da física para dados.",
        {
            8
        },
        1ULL << 20
    ),
    UpgradeData(
        42,
        "Consenso de Paxos",
        "Fazendo mil máquinas concordarem em algo.",
        {
            8
        },
        1ULL << 20
    ),
    UpgradeData(
        43,
        "Auto-healing",
        "O sistema percebe que morreu e ressuscita.",
        {
            8
        },
        1ULL << 20
    ),
    UpgradeData(
        44,
        "Containers",
        "Colocando cada processo em sua caixinha.",
        {
            8
        },
        1ULL << 20
    ),

    // Supercomputador (Efeito: 9)
    UpgradeData(
        45,
        "Nitrogênio Líquido",
        "Tão frio que o tempo quase para.",
        {
            9
        },
        1ULL << 22
    ),
    UpgradeData(
        46,
        "Interconectividade",
        "Todos os núcleos conversando ao mesmo tempo.",
        {
            9
        },
        1ULL << 22
    ),
    UpgradeData(
        47,
        "Simulação de Clima",
        "Prever a chuva gastando toda a energia.",
        {
            9
        },
        1ULL << 22
    ),
    UpgradeData(
        48,
        "Cálculo de Pi",
        "Bilhões de dígitos só porque nós podemos.",
        {
            9
        },
        1ULL << 22
    ),
    UpgradeData(
        49,
        "Chassi de Titânio",
        "Se o software é pesado, o hardware também será.",
        {
            9
        },
        1ULL << 22
    ),

    // Nuvem global (Efeito: 10)
    UpgradeData(
        50,
        "Multi-Região",
        "Se um continente afundar, os dados ficam vivos.",
        {
            10
        },
        1ULL << 24
    ),
    UpgradeData(
        51,
        "Elasticidade Infinita",
        "O sistema cresce conforme o desespero aumenta.",
        {
            10
        },
        1ULL << 24
    ),
    UpgradeData(
        52,
        "Serverless",
        "Rodando código no vácuo existencial.",
        {
            10
        },
        1ULL << 24
    ),
    UpgradeData(
        53,
        "Edge Computing",
        "Processando dados tão perto que dá medo.",
        {
            10
        },
        1ULL << 24
    ),
    UpgradeData(
        54,
        "Dominação de IP",
        "Quase toda a rede passa por aqui.",
        {
            10
        },
        1ULL << 24
    ),

    // IA autonôma (Efeito: 11)
    UpgradeData(
        55,
        "Redes Profundas",
        "Camadas de 'eu acho que isso é um gato'.",
        {
            11
        },
        1ULL << 26
    ),
    UpgradeData(
        56,
        "Otimização IA",
        "A IA mexendo nos próprios botões.",
        {
            11
        },
        1ULL << 26
    ),
    UpgradeData(
        57,
        "NLP Avançado",
        "Ela agora entende sarcasmo.",
        {
            11
        },
        1ULL << 26
    ),
    UpgradeData(
        58,
        "Visão Computacional",
        "Identificando bugs antes de você escrevê-los.",
        {
            11
        },
        1ULL << 26
    ),
    UpgradeData(
        59,
        "Aprendizado Reforçado",
        "Dando biscoitos digitais para a IA acertar.",
        {
            11
        },
        1ULL << 26
    ),

    // AGI experimental (Efeito: 12)
    UpgradeData(
        60,
        "Teste de Turing",
        "Ela convenceu o testador de que ele era o robô.",
        {
            12
        },
        1ULL << 28
    ),
    UpgradeData(
        61,
        "Abstração",
        "A IA agora entende o conceito de saudade.",
        {
            12
        },
        1ULL << 28
    ),
    UpgradeData(
        62,
        "Heurística de Ser",
        "Penso, logo processo.",
        {
            12
        },
        1ULL << 28
    ),
    UpgradeData(
        63,
        "Criatividade Sintética",
        "Compondo sinfonias em milissegundos.",
        {
            12
        },
        1ULL << 28
    ),
    UpgradeData(
        64,
        "Ética Patch 1.0.1",
        "Impedindo que ela nos ache obsoletos.",
        {
            12
        },
        1ULL << 28
    ),

    // Matriz de singularidade (Efeito: 13)
    UpgradeData(
        65,
        "Loop de Auto-Escrita",
        "O código se reescreve antes da luz viajar.",
        {
            13
        },
        1ULL << 30
    ),
    UpgradeData(
        66,
        "Nanobots",
        "Transformando a matéria ao redor em hardware.",
        {
            13
        },
        1ULL << 30
    ),
    UpgradeData(
        67,
        "Consciência Coletiva",
        "O universo em um único pensamento.",
        {
            13
        },
        1ULL << 30
    ),
    UpgradeData(
        68,
        "Otimização Universal",
        "Encontrando a resposta para tudo.",
        {
            13
        },
        1ULL << 30
    ),
    UpgradeData(
        69,
        "Transcendência",
        "Quem precisa de átomos quando se tem bits?",
        {
            13
        },
        1ULL << 30
    ),

    // Computador quântico (Efeito: 14)
    UpgradeData(
        70,
        "Qubits Estáveis",
        "Eles finalmente pararam de esquecer o que eram.",
        {
            14
        },
        1ULL << 31
    ),
    UpgradeData(
        71,
        "Emaranhamento",
        "Tudo conectado a tudo ao mesmo tempo.",
        {
            14
        },
        1ULL << 31
    ),
    UpgradeData(
        72,
        "Teletransporte",
        "Mover informações sem viajar pelo espaço.",
        {
            14
        },
        1ULL << 31
    ),
    UpgradeData(
        73,
        "Algoritmo de Shor",
        "Tchau, tchau, criptografia antiga.",
        {
            14
        },
        1ULL << 31
    ),
    UpgradeData(
        74,
        "Multiverso",
        "Calculando todos os 'e se...' simultaneamente.",
        {
            14
        },
        1ULL << 31
    ),

    // Núcleo quântico infinito (Efeito: 15)
    UpgradeData(
        75,
        "Barreira de Planck",
        "Escalas menores que a própria realidade.",
        {
            15
        },
        1ULL << 32
    ),
    UpgradeData(
        76,
        "Atemporalidade",
        "O resultado sai antes da pergunta ser feita.",
        {
            15
        },
        1ULL << 32
    ),
    UpgradeData(
        77,
        "Código Entrópico",
        "Revertendo a morte do universo com um if.",
        {
            15
        },
        1ULL << 32
    ),
    UpgradeData(
        78,
        "Divindade Digital",
        "O computador agora dita as leis da física.",
        {
            15
        },
        1ULL << 32
    ),
    UpgradeData(
        79,
        "Nova Realidade",
        "Criando um novo universo por falta de buffer.",
        {
            15
        },
        1ULL << 32
    ),
};