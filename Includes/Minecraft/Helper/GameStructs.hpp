#pragma once

#include "Minecraft/Helper/GameEnums.hpp"
#include "Minecraft/gstd/gstd.hpp"
#include "Structs.hpp"
#include "string"
#include "types.h"
#include <vector>

namespace MC3DSPluginFramework
{

    struct EffectData {
        u32 effectID;
        u32 time;
        u32 level;
        u32 unk;
    };

    struct BlockData {
        BlockId blockId = *(BlockId *)0xA34724;
        u8 dataId       = 0;

        BlockData() = default;

        BlockData(BlockId id, u8 data) :
            blockId(id), dataId(data) {}

        BlockData(BlockData &other)
        {
            blockId = other.blockId;
            dataId  = other.dataId;
        }
    };

    struct ScreenID {
        static inline const char *saving_screen                       = "saving_screen";
        static inline const char *sd_card_landing_screen              = "sd_card_landing_screen";
        static inline const char *pausedbyhost_screen                 = "pausedbyhost_screen";
        static inline const char *pause_screen                        = "pause_screen";
        static inline const char *progress_screen                     = "progress_screen";
        static inline const char *hud_screen                          = "hud_screen";
        static inline const char *credits_screen                      = "credits_screen";
        static inline const char *confirm_multiplayer_screen          = "confirm_multiplayer_screen";
        static inline const char *disconnect_realms_disconnect_screen = "disconnect.realms_disconnect_screen";
        static inline const char *system_messages_screen              = "system_messages_screen";
        static inline const char *base_screen                         = "base_screen";
        static inline const char *death_screen                        = "death_screen";
        static inline const char *error_screen                        = "error_screen";
        static inline const char *in_bed_screen                       = "in_bed_screen";
        static inline const char *store_screen                        = "store_screen";
        static inline const char *trade_screen                        = "trade_screen";
        static inline const char *hopper_screen                       = "hopper_screen";
        static inline const char *brewing_screen                      = "brewing_screen";
        static inline const char *confirm_screen                      = "confirm_screen";
        static inline const char *end_poem_screen                     = "end_poem_screen";
        static inline const char *loading_screen                      = "loading_screen";
        static inline const char *options_screen                      = "options_screen";
        static inline const char *modal_screen                        = "modal_screen";
        static inline const char *achievement_screen                  = "achievement_screen";
        static inline const char *realms_pending_invitations_screen   = "realms_pending_invitations_screen";
        static inline const char *creative_inventory_screen           = "creative_inventory_screen";
        static inline const char *language_screen                     = "language_screen";
        static inline const char *anvil_screen                        = "anvil_screen";
        static inline const char *chest_screen                        = "chest_screen";
        static inline const char *horse_screen                        = "horse_screen";
        static inline const char *skin_item_screen                    = "skin_item_screen";
        static inline const char *text_edit_screen                    = "text_edit_screen";
        static inline const char *beacon_screen                       = "beacon_screen";
        static inline const char *in_game_play_screen                 = "in_game_play_screen";
        static inline const char *leave_level_screen                  = "leave_level_screen";
        static inline const char *furnace_screen                      = "furnace_screen";
        static inline const char *patch_notes_screen                  = "patch_notes_screen";
        static inline const char *base_survival_screen                = "base_survival_screen";
        static inline const char *disconnection_screen                = "disconnection_screen";
        static inline const char *enchanting_screen                   = "enchanting_screen";
        static inline const char *store_item_list_screen              = "store_item_list_screen";
        static inline const char *mashup_pack_item_screen             = "mashup_pack_item_screen";
        static inline const char *survival_inventory_screen           = "survival_inventory_screen";
        static inline const char *quit_without_save_screen            = "quit_without_save_screen";
        static inline const char *tabbed_survival_screen              = "tabbed_survival_screen";
        static inline const char *dropper_dispenser_screen            = "dropper_dispenser_screen";
        static inline const char *max_worlds_message_screen           = "max_worlds_message_screen";
        static inline const char *cubemap_background_screen           = "cubemap_background_screen";
        static inline const char *multiplayer_choice_screen           = "multiplayer_choice_screen";
        static inline const char *confirm_no_achievements_screen      = "confirm_no_achievements_screen";
        static inline const char *confirm_unowned_texture_pack_screen = "confirm_unowned_texture_pack_screen";
        static inline const char *vr_show_comfort_select_screen       = "vr_show_comfort_select_screen";

        static inline const char *main_menu  = "main_menu";
        static inline const char *start_menu = "start_menu";
    };

    struct UniqueID {
        u32 mUnk1;
        u32 mUnk2;

        UniqueID(UniqueID &other)
        {
            memcpy(this, &other, sizeof(UniqueID));
        }
    };

    // FloatColor
    struct FColor {
        float r;
        float g;
        float b;
        float unk;    // a?

        FColor(float r, float g, float b) :
            r(r), g(g), b(b) {}

        FColor(const FColor &other)
        {
            memcpy(this, &other, sizeof(FColor));
        }
    };

    // ByteColor
    struct BColor {
        u8 b;
        u8 g;
        u8 r;
        u8 a;

        BColor(u8 r, u8 g, u8 b) :
            r(r), g(g), b(b), a(255) {}

        BColor(const BColor &other)
        {
            memcpy(this, &other, sizeof(BColor));
        }

        int toInt(void) const
        {
            return b | (g << 8) | (r << 16) | (a << 24);
        }
    };

}    // namespace MC3DSPluginFramework