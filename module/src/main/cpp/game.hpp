//
// Created by Perfare on 2020/7/4.
//

#ifndef UMAMUSUMELOCALIFYANDROID_GAME_HPP
#define UMAMUSUMELOCALIFYANDROID_GAME_HPP

#define GamePackageName "jp.co.cygames.umamusume"
#define GamePackageNameKor "com.kakaogames.umamusume"
#define GamePackageNameCht "com.komoe.kmumamusumegp"

enum class GameRegion {
    UNKNOWN,
    JAP,
    KOR,
    CHT
};

extern GameRegion gameRegion;

namespace {
    std::string GetCurrentPackageName() {
        if (gameRegion == GameRegion::JAP)
            return GamePackageName;
        if (gameRegion == GameRegion::KOR)
            return GamePackageNameKor;
        if (gameRegion == GameRegion::CHT)
            return GamePackageNameCht;
        return "";
    }
}

#endif //UMAMUSUMELOCALIFYANDROID_GAME_HPP
