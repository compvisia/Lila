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
        ASSET_TYPE_NONE,
        ASSET_TYPE_AUDIO,
        ASSET_TYPE_MATERIAL,
        ASSET_TYPE_MODEL,
        ASSET_TYPE_REFOBJ,
        ASSET_TYPE_TEXTURE,
        ASSET_TYPE_CUSTOM
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