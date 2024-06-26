#pragma once

#include "Asset.h"

#include "Lila/Core/Logger.h"
#include "Lila/Utils/Memory.h"

#include "Platform/Defines.h"

#include <vector>
#include <unordered_map>

namespace Lila {
    
    /**
     * @brief A manager for all asset you need.
     * 
     * @todo More management from the manager (something like `Shared<Asset> createAsset(std::string path)`).
     * @todo Self-asigning Asset (e.g. if you have .png at the end it knows it's a texture).
     * 
     * @see Asset.
     */
    class AssetManager {
    public:
        AssetManager();

        Shared<Asset> registerAsset(Asset asset);

        Shared<Asset> loadAsset(u64 assetId);
        void unloadAsset(u64 assetId);

        Shared<Asset> getAsset(u64 assetId);
        Shared<Asset> getLoadedAsset(u64 assetId);
        
        b8 isAssetLoaded(u64 assetId);

    private:
        std::vector<Shared<Asset>> loaded_m;
        std::unordered_map<u64, Shared<Asset>> assets_m;
    };

} // namespace Lila