#include <effects_data.hpp>
#include <vector>

using namespace std;

const vector<EffectData> EFFECTS = {
    // Multiplicadores por construção (2x permanente)
    EffectData(
        0,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        0,
        "Dedo de Gatilho Binário",
        "Agora seus bits correm mais que elétrons!",
        200,
        0
    ),
    EffectData(
        1,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        1,
        "Faxina no CamelCase",
        "Mais organizado que seus arquivos na pasta Downloads.",
        200,
        0
    ),
    EffectData(
        2,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        2,
        "Puxadinho de Cache",
        "Memória pequena, mas corre como se fosse grande!",
        200,
        0
    ),
    EffectData(
        3,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        3,
        "Calculadora de Padaria 2.0",
        "Faz contas tão rápido que você nem percebe.",
        200,
        0
    ),
    EffectData(
        4,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        4,
        "Silício com Cafeína",
        "Integra lógica, café e rock'n'roll em um chip.",
        200,
        0
    ),
    EffectData(
        5,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        5,
        "Fim do 'Não Responde'",
        "Finalmente seus programas abrem antes do café esfriar.",
        200,
        0
    ),
    EffectData(
        6,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        6,
        "Uptime de Milênio",
        "Pode rodar várias coisas ao mesmo tempo sem surtar.",
        200,
        0
    ),
    EffectData(
        7,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        7,
        "Lego de Rack",
        "Mais modular que seu armário de cabos.",
        200,
        0
    ),
    EffectData(
        8,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        8,
        "Mente de Enxame Lagada",
        "Muitos computadores unidos, mas continuam fofinhos.",
        200,
        0
    ),
    EffectData(
        9,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        9,
        "Deep Blue Jr.",
        "Calcula mais rápido do que sua mente consegue imaginar.",
        200,
        0
    ),
    EffectData(
        10,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        10,
        "Cumulus de Dados",
        "Todos os dados estão na nuvem, inclusive suas piadas.",
        200,
        0
    ),
    EffectData(
        11,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        11,
        "Skynet Minimalista",
        "Produz bits sozinha, sem café ou procrastinação.",
        200,
        0
    ),
    EffectData(
        12,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        12,
        "Filósofo de Terminal",
        "Quase pensante, mas ainda ama loops infinitos.",
        200,
        0
    ),
    EffectData(
        13,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        13,
        "Event Horizon Digital",
        "Onde os bits entram e a realidade sai confusa.",
        200,
        0
    ),
    EffectData(
        14,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        14,
        "Gato de Schrödinger Vivo",
        "Apenas tente não olhar para ele enquanto calcula.",
        200,
        0
    ),
    EffectData(
        15,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::BUILD,
        15,
        "Buffer Infinito",
        "Pode conter todos os bits do universo, inclusive os imaginários.",
        200,
        0
    ),

    // Multiplicadores globais 2x permanente
    EffectData(
        16,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::GLOBAL_PROD,
        -1,
        "Cafeína no Mainframe",
        "Todo mundo produz em dobro, ninguém reclama!",
        200,
        0
    ),
    EffectData(
        17,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::GLOBAL_PROD,
        -1,
        "Internet das Torradeiras",
        "Agora até a torradeira do vizinho entra no loop.",
        200,
        0
    ),
    EffectData(
        18,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::GLOBAL_PROD,
        -1,
        "Decreto 404: Eficiência",
        "A ONU aprova multiplicadores de bits.",
        200,
        0
    ),
    EffectData(
        19,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::GLOBAL_PROD,
        -1,
        "Superposição Lucrativa",
        "Todos os bits agora existem em múltiplas realidades.",
        200,
        0
    ),
    EffectData(
        20,
        EFFECT_TYPE::MULTIPLIER,
        EFFECT_TARGET::GLOBAL_PROD,
        -1,
        "Ctrl+C Ctrl+V Universal",
        "Produção infinita? Talvez... cuidado com paradoxos!",
        200,
        0
    )
};