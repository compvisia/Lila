#include "AssetManager.h"

namespace Lila {

    /**
     * @brief Constructor
    */ 
    AssetManager::AssetManager() {}

    /**
     * @brief Registers a asset.
     * 
     * Registering an asset will create a shared pointer and store it in a unordered_map.
     * 
     * @param asset A struct of type Asset.
     * @return Shared pointer of Asset managed by this class.
    */    
    Shared<Asset> AssetManager::registerAsset(Asset asset) {
        Shared<Asset> obj = makeShared<Asset>();
        obj->assetId = asset.assetId;
        obj->type = asset.type;
        obj->path = asset.path;
        
        assets_m[asset.assetId] = obj;
        
        return obj;
    }

    /**
     * @brief Loads an asset.
     * 
     * An asset is a file that is used in the game. 
     * For example, an .mp3 file is an asset. A png is also an asset.
     * 
     * @param assetId An id that is used for loading the asset.
     * @return A shared pointer of the asset managed by this class.
    */
    Shared<Asset> AssetManager::loadAsset(u64 assetId) {        
        Shared<Asset> obj = assets_m[assetId];

        loaded_m.push_back(obj);
        
        return obj;
    }
    
        /**
     * @brief Unloads an asset.
     * 
     * @param assetId An id that is used for unloading the asset.
     * @return A shared pointer of the asset managed by this class.
    */
    void AssetManager::unloadAsset(u64 assetId) {    
        u64 location = 0;

        for(u64 i = 0; i < loaded_m.size(); i++) {
            if(loaded_m[i]->assetId != assetId)
                continue;

            location = i;
            break;
        }

        loaded_m.erase(loaded_m.begin() + location);
    }
    
    /**
     * @brief Gets asset using an id.
     * 
     * @param assetId An id that is used for getting the asset.
     * @return A shared pointer of the asset managed by this class.
    */
    Shared<Asset> AssetManager::getAsset(u64 assetId) {
        return assets_m[assetId];
    }
    
    /**
     * @brief Gets loaded asset using an id.
     * 
     * @param assetId An id that is used for getting the loaded asset.
     * @return A shared pointer of the asset managed by this class. or nullptr if not found.
    */
    Shared<Asset> AssetManager::getLoadedAsset(u64 assetId) {
        for(u64 i = 0; i < loaded_m.size(); i++) {
            if(loaded_m[i]->assetId != assetId)
                continue;
            
            return loaded_m[i];
        }

        lila_error("Asset is not loaded!");

        return nullptr;
    }

    /**
     * @brief Checks if the asset is loaded using an id.
     * 
     * @param assetId An id that is used for checking if the asset is loaded.
     * @return A boolean.
    */
    b8 AssetManager::isAssetLoaded(u64 assetId) {
        for(u64 i = 0; i < loaded_m.size(); i++) {
            if(loaded_m[i]->assetId != assetId)
                continue;
            
            return true;
        }

        return false;
    }

} // namespace Lila
