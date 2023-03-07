#include "plugin.h"

using namespace plugin;

class SapoNaoLavaoPe {
public:




    SapoNaoLavaoPe() {
        // faz uma desert eagle ser q nem uma minigun, é divertido kkkkk
        Transferir(WEAPON_MINIGUN, WEAPON_DESERT_EAGLE);
    }

    void Transferir(eWeaponType weaponData, eWeaponType weaponTarget, bool alterAnim = false) {
        static eWeaponType weapon1 = weaponData, weapon2 = weaponTarget;

        static bool AlterAnim = alterAnim;
        Events::processScriptsEvent += [] {
            CPlayerPed* player = FindPlayerPed();
            
            CWeaponInfo* WeaponData = CWeaponInfo::GetWeaponInfo(weapon1, player->GetWeaponSkill());
            CWeaponInfo* WeaponTarget = CWeaponInfo::GetWeaponInfo(weapon2, player->GetWeaponSkill());
            unsigned int
                slot = WeaponTarget->m_nSlot,
                AnimToPlay = WeaponTarget->m_nAnimToPlay;

            unsigned short AimOffSet = WeaponTarget->m_nAimOffsetIndex;

            int 
                modelid1 = WeaponTarget->m_nModelId1, 
                modelid2 = WeaponTarget->m_nModelId2;

            auto flags = WeaponTarget->m_nFlags;


            
            // faz uma copia de WeaponData para WeaponTarget
            *WeaponTarget = *WeaponData;


            // Arruma o necessario, c não vira uma m4 2.0
            WeaponTarget->m_nSlot = slot;
            WeaponTarget->m_nModelId1 = modelid1;
            WeaponTarget->m_nModelId2 = modelid2;
            WeaponTarget->m_nFlags = flags;
            WeaponTarget->m_nAimOffsetIndex = AimOffSet;

            if (!AlterAnim) {
                WeaponTarget->m_nAnimToPlay = AnimToPlay;
            }

        };
    }

} sapoNaoLavaoPe;

