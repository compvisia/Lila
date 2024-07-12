#pragma once

#include "Platform/Defines.h"

#include <string>

namespace Lila {

    /**
     * @brief An enum used for all types of assets.
     * 
     * An asset always has a type, whether it's a mp3 (Audio) or a png (Texture).
    */
    typedef enum AssetType {
        ASSET_TYPE_NONE,        // Asset does not exist
        ASSET_TYPE_AUDIO,       // Audio files (.mp3, .wav, .ogg)
        ASSET_TYPE_FONT,        // Font files
        ASSET_TYPE_MATERIAL,    // Material files
        ASSET_TYPE_MODEL,       // Models files (.obj)
        ASSET_TYPE_REFOBJ,      // Objects that are not being used (Unity term: Prefabs)
        ASSET_TYPE_TEXTURE,     // Texture files (.png, .jpeg, .svg)
        ASSET_TYPE_OTHER,       // Files that have not been named yet
        ASSET_TYPE_CUSTOM       // Custom files that the user can implement (maybe something obsolete)
    };

    /**
     * @brief A data-only struct.
     * 
     * The concept of an asset is that it's a file that the game uses which the user decides.
     * 
     * @param assetId An unique identifier.
     * @param type Type of asset.
     * @param path An absolute path to the asset.
    */
    struct Asset {
        u64 assetId;
        AssetType type;
        std::string path;
    };

} // namespace Lila